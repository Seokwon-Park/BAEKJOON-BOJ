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

int v[1005][1005];
bool vis[1005][1005];
pii coord[1000005];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	set<int, greater<int>> st;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			coord[v[i][j]] = { i,j };
			if (i == 0 || j == 0 || i == n-1 || j== m-1)
			{
				st.insert(v[i][j]);
			}
		}
	}

	int k;
	cin >> k;
	vector<pii> ans;
	while (k--)
	{
		int tp = *st.begin();
		st.erase(tp);
		auto [r, c] = coord[tp];
		vis[r][c] = true;
		ans.push_back({ r + 1,c + 1 });
		for (int i = 0; i < 4; i++)
		{
			int rr = r + dy[i];
			int cc = c + dx[i];
			if (vis[rr][cc] || rr < 0 || cc < 0 || rr >= n || cc >= m) continue;
			st.insert(v[rr][cc]);
		}
	}

	for (auto [r, c] : ans)
	{
		cout << r << ' ' << c << '\n';
	}

	return 0;
}