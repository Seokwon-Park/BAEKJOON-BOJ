#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int b[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int len = 1; len <= n; len++)
	{
		bool isUni = true;

		for (int st = 0; st < n - len+1; st++)
		{
			string pat = s.substr(st, len);
			for (int i = 0; i < n - len+1; i++)
			{
				if (st == i)continue;
				if (pat == s.substr(i, len))
				{
					isUni = false;
				}
			}
		}
		if (isUni)
		{
			cout << len;
			return 0;
		}
	}

	return 0;
}
