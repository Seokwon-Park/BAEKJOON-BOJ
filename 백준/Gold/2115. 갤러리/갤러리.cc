#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;
template <typename key, typename value>
using hashm = unordered_map<key, value>;

char b[1005][1005];
bool isUsed[1005][1005][4]; // l,u,r,d;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}

	int ans = 0;
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < m - 1; j++)
		{
			if (b[i][j] == 'X') continue;
			if (b[i][j + 1] == '.')
			{
				if (!isUsed[i][j][1] && b[i - 1][j] == 'X' && b[i - 1][j + 1] == 'X')
				{
					isUsed[i][j][1] = true;
					isUsed[i][j + 1][1] = true;
					ans++;
				}
				if (!isUsed[i][j][3] && b[i + 1][j] == 'X' && b[i + 1][j + 1] == 'X')
				{
					isUsed[i][j][3] = true;
					isUsed[i][j + 1][3] = true;
					ans++;
				}
			}
			if (b[i + 1][j] == '.')
			{
				if (!isUsed[i][j][0] && b[i][j - 1] == 'X' && b[i + 1][j - 1] == 'X')
				{
					isUsed[i][j][0] = true;
					isUsed[i + 1][j][0] = true;
					ans++;
				}
				if (!isUsed[i][j][2] && b[i][j + 1] == 'X' && b[i + 1][j + 1] == 'X')
				{
					isUsed[i][j][2] = true;
					isUsed[i + 1][j][2] = true;
					ans++;
				}
			}
		}
	}
	cout << ans;



	return 0;
}