#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int n;
int b[21][21];
bool v[21][21];
int dist[21][21];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int sz = 2;

void resetv()
{
	for (int i = 0; i < n; i++)
	{
		fill(v[i], v[i] + n, false);
	}
}

int bfs(int sx, int sy, int ex, int ey)
{
	resetv();
	queue<pii>q;
	q.push({ sx,sy });
	v[sy][sx] = true;
	int dist = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int j = 0; j < qs; j++)
		{
			auto [cx, cy] = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int tx = cx + dx[i];
				int ty = cy + dy[i];
				if (tx < 0 || ty < 0 || tx >= n || ty >= n)continue;
				if (v[ty][tx] || b[ty][tx] > sz) continue;
				if (ty == ey && tx == ex)
				{
					return dist + 1;
				}
				q.push({ tx,ty });
				v[ty][tx] = true;
			}
		}
		dist++;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x = 0 , y = 0;
	int exp = 0;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 9)
			{
				x = j;
				y = i;
			}

		}

	int ans = 0; // 총 움직인 거리
	while (1)
	{
		int dist = 0; // 다음 먹이까지의 거리
		int tx = 0; // 다음 먹이의 x좌표
		int ty = 0; // 다음 먹이의 y좌표
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (b[i][j] == 9) continue; // 자기 자신이면 넘겨
				if (b[i][j] != 0 && b[i][j] < sz) //만약 먹을 수 있는 걸 찾았으면
				{
					if (dist == 0)// 이전에 찾은 먹이가 아직 없으면 (1마리 발견)
					{
						dist = bfs(x, y, j, i);
						tx = j;
						ty = i;
					}
					else // 먹을 수 있는 물고기가 1마리 보다 많다면.
					{
						int newdist = bfs(x,y,j,i); // 일단 새 거리 계산
						if (newdist == 0) continue; // 만약 목표한 곳에 도달할수 없다면 다음 루프로
						if (newdist < dist) // 더 가까우면 목표 먹이를 갱신
						{
							dist = newdist;
							tx = j;
							ty = i;
						}
						else if (newdist == dist) //거리가 가까운 물고기가 여러마리인 경우
						{
							if (i < ty) // 더 윗 칸에 있으면
							{
								dist = newdist;
								tx = j;
								ty = i;
							}
							else if (i == ty) // 높이도 같으면
							{
								if (j < tx) // 더 왼쪽이라면
								{
									dist = newdist;
									tx = j;
									ty = i;
								}
							}
						}

					}
				}
			}
		}
		if (dist == 0) break; // 만약 먹을 걸 못찾았으면 끝
		// 여기 도달했으면 먹을 거 찾은 상태라는 뜻
		// 상어 위치 갱신하고 이동한 거리 추가.
		b[y][x] = 0;
		x = tx;
		y = ty;
		b[y][x] = 9;
		exp++;
		if (exp == sz) // 레벨업
		{
			sz++;
			exp = 0;
		}
		ans += dist;

		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < n; j++)
		//	{
		//		cout << b[i][j] << ' ';
		//	}
		//	cout << '\n';
		//}
		//cout << ans << ' ' << sz;
		//cout << '\n';
	}
	cout << ans;


	return 0;
}