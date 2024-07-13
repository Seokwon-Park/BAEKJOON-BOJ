#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	cin.ignore();
	while (tc--)
	{
		string s;
		getline(cin, s);
		vector<int> v(26, 0);
		for (auto c : s)
		{
			if(c >= 'a' && c<='z')
				v[c - 'a']++;
		}
		auto mx = max_element(v.begin(), v.end());
		if (count(v.begin(), v.end(), *mx) == 1)
		{
			cout << (char)('a' + (int)(mx - v.begin()));
		}
		else
		{
			cout << '?';
		}
		cout << '\n';
	}
	return 0;
}