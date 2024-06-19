#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

char b[1000][1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m * 5 + 1; i++)
	{
		for (int j = 0; j < n * 5 + 1; j++)
		{
			cin >> b[i][j];
		}
	}

	vector<int> ans(5, 0);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				if (b[i * 5 + 1 + k][j * 5 + 1] == '*')
					cnt++;
			}
			ans[cnt]++;
		}
	}

	for (auto i : ans)
		cout << i << ' ';


	return 0;
}
