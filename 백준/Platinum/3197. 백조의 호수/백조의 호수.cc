#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

char board[1505][1505];
int bmap[1505][1505];
bool visited[1505][1505];
vector<int> p(1505 * 1505, -1);
int h, w;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
queue<pair<int, int>> q2;
vector<pair<int, int>> lpos;


void resetv()
{
	for (int i = 0; i < h; i++)
	{
		fill(visited[i], visited[i] + w, false);
	}
}

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void union_(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return;
	if (p[a] < p[b]) p[b] = a;
	else p[a] = b;
}

bool is_same_group(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return true;
	else return false;
}

void find_surface(int x, int y)
{
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[y][x] = true;
	while (!q.empty())
	{
		bool is_surface = false;
		auto [cx, cy] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = cx + dx[i];
			int ty = cy + dy[i];
			if (tx < 0 || ty < 0 || tx >= w || ty >= h) continue;
			if (visited[ty][tx]) continue;
			if (board[ty][tx] == 'X')
			{
				is_surface = true;
				continue;
			}
			union_(bmap[ty][tx], bmap[cy][cx]);
			q.push({ tx,ty });
			visited[ty][tx] = true;
		}
		if (is_surface)
		{
			q2.push({ cx, cy });
		}
	}
}

int bfs()
{
	int t = 0;
	if (is_same_group(bmap[lpos[0].second][lpos[0].first], bmap[lpos[1].second][lpos[1].first]))
	{
		return t;
	}
	t++;
	while (!q2.empty())
	{
		int qs = q2.size();

		//for (int i = 0; i < h; i++)
		//{
		//	for (int j = 0; j < w; j++)
		//	{
		//		/*cout << p[bmap[i][j]] << '\t';*/
		//		cout <<board[i][j];
		//	}
		//	cout << '\n';
		//}

		for (int j = 0; j < qs; j++)
		{
			auto [x, y] = q2.front();
			q2.pop();

			for (int i = 0; i < 4; i++)
			{
				int tx = x + dx[i];
				int ty = y + dy[i];
				if (tx < 0 || ty < 0 || tx >= w || ty >= h) continue;
				if (visited[ty][tx])continue;
				if (board[ty][tx] == 'X')
				{
					board[ty][tx] = '.';
					union_(bmap[ty][tx], bmap[y][x]);
				}
				for (int i = 0; i < 4; i++)
				{
					int ttx = tx + dx[i];
					int tty = ty + dy[i];
					if (ttx < 0 || tty < 0 || ttx >= w || tty >= h) continue;
					if (board[tty][ttx] != 'X')
					{
						union_(bmap[tty][ttx], bmap[ty][tx]);
					}
				}
				q2.push({ tx,ty });
				visited[ty][tx] = true;
			}
		}

		//cout << '\n';
		//cout << find(bmap[lpos[0].second][lpos[0].first]) << ' ' << find(bmap[lpos[1].second][lpos[1].first]) << '\n';
		if (is_same_group(bmap[lpos[0].second][lpos[0].first], bmap[lpos[1].second][lpos[1].first]))
		{
			return t;
		}

		t++;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> h >> w;


	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'L')
			{
				lpos.push_back({ j,i });
			}
			bmap[i][j] = i * w + j;
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (board[i][j] != 'X' && !visited[i][j])
			{
				find_surface(j, i);
			}
		}
	}
	
	cout << bfs();


	return 0;
}