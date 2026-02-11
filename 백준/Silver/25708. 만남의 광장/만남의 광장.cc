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

int v[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> rowsum(n);
	vector<int> colsum(m);
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			rowsum[i] += v[i][j];
			colsum[j] += v[i][j];
		}
	}

	int ans = INT_MIN;
	for (int re = 1; re < n; re++)
	{
		for (int rs = 0; rs < re; rs++)
		{
			for (int ce = 1; ce < m; ce++)
			{
				for (int cs = 0; cs < ce; cs++)
				{
					int res = rowsum[re] + rowsum[rs] + colsum[ce] + colsum[cs]
						- v[re][ce] - v[re][cs] - v[rs][ce] - v[rs][cs];
					res += (re - rs - 1) * (ce - cs - 1);
					ans = max(ans, res);
				}
			}
		}
	}

	cout << ans;

	return 0;
}
