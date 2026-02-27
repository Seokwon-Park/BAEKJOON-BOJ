#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int b[115][115];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{

		int n, p, m;
		cin >> n >> p >> m;
		vector<pii> v(p);

		for (int i = 1; i <= n; i++)
		{
			fill(b[i] + 1, b[i] + n + 1, INF);
			b[i][i] = 0;
		}
		for (int i = 0; i < p; i++)
		{
			int x, vi;
			cin >> x >> vi;
			v[i] = { x,vi };
		}

		for (int i = 0; i < m; i++)
		{
			int di, li;
			cin >> di >> li;
			int prev = -1;
			for (int i = 0; i < li; i++)
			{
				int x;
				cin >> x;
				if (prev != -1)
				{
					b[prev][x] = di;
					b[x][prev] = di;
				}
				prev = x;
			}
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				for (int k = 1; k <= n; k++)
				{
					if (j == k) continue;
					b[j][k] = min(b[j][k], b[j][i] + b[i][k]);
				}
			}
		}
		vector<int> cand(n + 1);
		for (int i = 1; i <= n; i++)
		{
			for (auto [x, vi] : v)
			{
				if (b[x][i] == INF)
				{
					cand[i] = INF;
					break;
				}
				cand[i] = max(cand[i], vi * b[x][i]);
			}
		}
		cout << "Case #" << tc << ": ";
		int res = *min_element(cand.begin() + 1, cand.end());
		cout << (res == INF ? -1 : res);
		cout << '\n';
	}

	return 0;
}