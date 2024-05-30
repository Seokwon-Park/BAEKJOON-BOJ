#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int n, m;
int cur;
int total;
int b[55][55];
bool v[55][55];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
vector<int> vp;
queue<pii> q;

int bfs()
{
	int t = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			auto [x, y] = q.front();
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx < 0 || ty < 0 || tx >= n || ty >= n)continue;
				if (v[ty][tx] || b[ty][tx] == 1) continue;
				q.push({ tx,ty });
				v[ty][tx] = true;
				cur--;
			}
		}
		if (q.empty())break;
		t++;
	}

	if (cur == 0)
		return t;
	else
		return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
			if (b[i][j] != 1)
			{
				total++;
			}
			if (b[i][j] == 2)
			{
				vp.push_back(i * n + j);
				b[i][j] = 0;
			}
		}
	}

	int ans = INT_MAX;
	vector<int> comb(vp.size(), 0);
	fill(comb.end() - m, comb.end(), 1);

	do
	{
		cur = total;
		for (int i = 0; i < n; i++)
			fill(v[i], v[i] + n, false);
		for (int i = 0; i < comb.size(); i++)
		{
			if (comb[i] == 1)
			{
				int x = vp[i] % n;
				int y = vp[i] / n;
				q.push({ x,y });
				v[y][x] = true;
				cur--;
			}
		}
		int res = bfs();
		if(res != -1)
			ans = min(ans, res);
		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < n; j++)
		//	{
		//		cout << b[i][j] << ' ';
		//	}
		//	cout << '\n';
		//}
	} while (next_permutation(comb.begin(), comb.end()));

	if (ans == INT_MAX)
		cout << -1;
	else
		cout << ans;


	return 0;
}