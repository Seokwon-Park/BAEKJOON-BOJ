#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

char b[405][405];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int r, c;
		cin >> r >> c;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> b[i][j];

		int ans = 0;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (j + 2 < c && b[i][j] == '>' && b[i][j + 1] == 'o' && b[i][j + 2] == '<')
					ans++;

			}
		}
		for (int i = 0; i < c; i++)
		{
			for (int j = 0; j < r; j++)
			{
				if (j + 2 < r && b[j][i] == 'v' && b[j + 1][i] == 'o' && b[j + 2][i] == '^')
					ans++;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
