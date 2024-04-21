#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int dx[6] = { -1,1,-2,2,-1,1 };
int dy[6] = { -2,-2,0,0,2,2 };
int n;
int r1, c1, r2, c2;
bool v[205][205];

int bfs(int x, int y)
{
	queue<pii>q;
	q.push({ x,y });
	v[y][x] = true;
	int moved = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int j = 0; j < qs; j++)
		{
			auto [cx, cy] = q.front();
			q.pop();
			for (int i = 0; i < 6; i++)
			{
				int tx = cx + dx[i];
				int ty = cy + dy[i];
				if (tx < 0 || ty < 0 || tx >= n || ty >= n)continue;
				if (v[ty][tx])continue;
				if (ty == r2 && tx == c2)
				{
					return moved + 1;
				}
				q.push({ tx,ty });
				v[ty][tx] = true;
			}
		}
		moved++;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;

	cout << bfs(c1, r1);

	return 0;
}