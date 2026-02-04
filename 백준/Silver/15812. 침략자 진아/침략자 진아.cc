#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int b[25][25];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pii> towns;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char ch;
			cin >> ch;
			b[i][j] = ch - '0';
			if (b[i][j] == 1)
			{
				towns.push_back({ i,j });
			}
		}
	}

	int ans = INF;
	for (int i = 0; i < n * m; i++)
	{
		for (int j = i+1; j < n * m; j++)
		{
			vector<int> mintime(towns.size(), INF);
			int x1 = i % m;
			int y1 = i / m;
			int x2 = j % m;
			int y2 = j / m;
			if (b[y1][x1] == 1 || b[y2][x2] == 1) continue;
			for (int k = 0; k < towns.size(); k++)
			{
				auto [ty, tx] = towns[k];
				mintime[k] = min(mintime[k], abs(tx - x1) + abs(ty - y1));
				mintime[k] = min(mintime[k], abs(tx - x2) + abs(ty - y2));
			}
			ans = min(ans, *max_element(mintime.begin(), mintime.end()));
		}
	}
	cout << ans;


	return 0;
}