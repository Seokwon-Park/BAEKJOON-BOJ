#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

char v[6][9];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<int>> rows(3, vector<int>(26, 0));
	vector<vector<int>> cols(3, vector<int>(26, 0));

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> v[i][j];
			int x = v[i][j] - 'A';
			rows[i / 2][x]++;
			cols[j / 3][x]++;
		}
	}

	int ans = INF;

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (i == j) continue;
			for (int k = 0; k < 26; k++)
			{
				if (k == j) continue;
				ans = min(ans, 54 - (rows[0][i] + rows[1][j] + rows[2][k]));
				ans = min(ans, 54 - (cols[0][i] + cols[1][j] + cols[2][k]));
			}
		}
	}

	cout << ans;

	return 0;
}