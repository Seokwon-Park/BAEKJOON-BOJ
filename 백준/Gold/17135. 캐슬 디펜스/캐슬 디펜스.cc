#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int n, m, d;
int borigin[20][20];
int b[20][20];
int ans;

void moveEnemy()
{
	for (int i = n-1; i > 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			b[i][j] = b[i - 1][j];
		}
	}
	fill(b[0], b[0] + m, 0);
}

pii findAndKillEnemy(pii archer_pos)
{
	auto [x, y] = archer_pos;
	int tx = -1, ty = -1; // target x y
	int mind = INF;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (b[i][j] == 0) continue;
			int dist = abs(i - y) + abs(j - x);
			if (dist > d) continue;
			if (dist < mind)
			{
				mind = dist;
				tx = j;
				ty = i;
			}
			else if (dist == mind && j < tx)
			{
				mind = dist;
				tx = j;
				ty = i;
			}
		}
	}
	return { tx,ty };
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> borigin[i][j];
		}
	}

	vector<bool> c(m, 0);
	fill(c.end() - 3, c.end(), 1);

	do
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				b[i][j] = borigin[i][j];
			}
		}
		int res = 0;
		vector<pii> archers;
		for (int i = 0; i < m; i++)
		{
			if (c[i])
				archers.push_back({ i, n }); // x, y;
		}

		for (int sim = 0; sim < n; sim++)
		{
			set<pii> targets;
			for (int i = 0; i < 3; i++)
			{
				pii tmp = findAndKillEnemy(archers[i]);
				if (tmp.first != -1 && tmp.second != -1)
				{
					targets.insert(tmp);
				}
			}
			for (auto [x, y] : targets)
			{
				b[y][x] = 0;
				res++;
			}
			moveEnemy();
		}
		ans = max(res, ans);
	} while (next_permutation(c.begin(), c.end()));

	cout << ans;

	return 0;
}