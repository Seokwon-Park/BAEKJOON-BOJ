#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<string>> v(n, vector<string>(3));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> v[i][j];
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		vector<string> q(3);
		for (int j = 0; j < 3; j++)
		{
			cin >> q[j];
		}

		int res = 0;
		for (int j = 0; j < n; j++)
		{
			bool isInclude = true;
			for (int k = 0; k < 3; k++)
			{
				if (q[k] == "-") continue;
				if (q[k] != v[j][k])
				{
					isInclude = false;
					break;
				}
			}
			res += isInclude;
		}
		cout << res << '\n';
	}


	return 0;
}