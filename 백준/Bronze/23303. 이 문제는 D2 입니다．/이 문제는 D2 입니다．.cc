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

	string s;
	getline(cin, s);
	for(int i = 0; i< s.size(); i++)
	{
		if (i < s.size() - 1 && (s[i] == 'd' || s[i] == 'D') && s[i + 1] == '2')
		{
			cout << "D2";
			return 0;
		}
	}

	cout << "unrated";
	return 0;
}
