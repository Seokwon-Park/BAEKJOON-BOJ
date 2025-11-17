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
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	set<int, greater<int>> st;
	priority_queue<pair<int, pii>> pq;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
			{
				pq.push({ v[i][j], {i,j} });
				vis[i][j] = true;
			}
		}
	}

	int k;
	cin >> k;
	vector<pii> ans;
	while (k--)
	{
		auto tp = pq.top();
		pq.pop();
		auto [r, c] = tp.second;
		ans.push_back({ r + 1,c + 1 });
		for (int i = 0; i < 4; i++)
		{
			int rr = r + dy[i];
			int cc = c + dx[i];
			if (vis[rr][cc] || rr < 0 || cc < 0 || rr >= n || cc >= m) continue;
			pq.push({ v[rr][cc], {rr,cc} });
			vis[rr][cc] = true;
		}
	}

	for (auto [r, c] : ans)
	{
		cout << r << ' ' << c << '\n';
	}

	return 0;
}
