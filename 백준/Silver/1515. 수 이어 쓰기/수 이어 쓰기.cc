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
	cin >> s;

	int cur = 1;
	int ix = 0;
	while (1)
	{
		string tmp = to_string(cur);
		for (int i = 0; i < tmp.size(); i++)
		{
			if (s[ix] == tmp[i])
				ix++;
			if (ix >= s.size())
			{
				cout << cur;
				return 0;
			}
		}
		cur++;
	}

	return 0;
}