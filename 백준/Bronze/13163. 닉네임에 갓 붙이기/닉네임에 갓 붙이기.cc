#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);
		istringstream iss(s);
		string tmp;
		vector < string> v;
		while (getline(iss, tmp, ' '))
		{
			v.push_back(tmp);
		}
		string ans = "god";
		for (int i = 1; i < v.size(); i++)
		{
			ans += v[i];
		}
		cout << ans << '\n';
	}

	return 0;
}