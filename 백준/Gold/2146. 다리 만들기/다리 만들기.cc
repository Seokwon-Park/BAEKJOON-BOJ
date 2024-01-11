#include <bits/stdc++.h>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int n;
int board[105][105];
bool visited[105][105];
bool copyv[105][105];
int d[105][105]; // 거리 테이블
int copyd[105][105]; // 거리 테이블
vector<pair<int, int>> build_loc;
int min_dst = INT_MAX;


void bfs_build(int x, int y) // 1을 찾을때까지 탐색
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[y][x] = true;
	int cur_ix = -board[y][x];
	while (!q.empty())
	{
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= n)continue;
			if (copyv[ty][tx]) continue;
			if (board[ty][tx] < 0 && board[ty][tx] != -cur_ix) 
			{// 다음 위치가 다른 섬의 다리를 놓을 수 있는 곳이라면 일단 현재 위치에서 
			// 다음 자리에 다리를 한칸 더 놓으면 건설이 끝난다는 뜻이다.
				// 완성된 다리가 최소 길이의 다리보다 더 짧은지 확인하고 갱신한다.
				min_dst = min(min_dst, copyd[ny][nx] + 1);
				break;
			}
			copyv[ty][tx] = true;
			if (copyd[ty][tx] != 0) // 0이라면 아직 한번도 이 경로를 통해본적이 없다는 것이기 때문에 이전 경로에서 1 추가해주고
				//아니라면 지금 건설중인 다리의 길이가 더 짧으면 갱신해준다.
			{
				copyd[ty][tx] = min(copyd[ny][nx] + 1, copyd[ty][tx]);
			}
			else
			{
				copyd[ty][tx] = copyd[ny][nx] + 1;

			}
			q.push({ tx,ty });
		}
	}
}


void bfs_find(int x, int y, int ix)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[y][x] = true;
	board[y][x] = ix;
	while (!q.empty())
	{
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= n)continue;
			if (visited[ty][tx])continue;
			if (board[ty][tx] < 0) // 만약 이미 다른 섬에서 다리를 놓을 수 있는 구역이면 겹쳐버리게 된다. 거리가 1이라는 소리
			{
				if(board[ty][tx] != -ix)
					min_dst = 1;
				continue;
			}
			if (board[ty][tx] == 0)
			{// 다음 위치가 바다라면 여기서부터 다리를 놓을수 있게된다.
				board[ty][tx] = -ix;
				d[ty][tx] = 1;
				continue;
			}
			board[ty][tx] = ix;
			visited[ty][tx] = true;
			q.push({ tx,ty });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	//일단 모든 섬을 찾아서 bfs돌리고 다음 영역이 0인 부분에 대해서 다리건설을 시작할 수 있는 위치로 설정
	// (board에 -ix로 표시하고 섬 넘버링을 ix로 바꾸자) 이유 : 내가 만약 바다(0)이 아닌 다른 블록과 부딪혔을때 
	// 그게 돌아서 같은 섬으로 온것인지, 다른 섬에 도착한 것인지 알수 없으므로 구분을 위해서
	int ix = 1;// 1번 섬이라는 뜻
	bool find = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 1 && visited[i][j] == false)
			{
				bfs_find(j, i, ix);
				ix++;
			}
		}
	}

	//cout << '\n';
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << visited[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';

	//cout << '\n';
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << board[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';

	//이제 다리 지을수 있는 위치 전부 찾아서 위치마다 다른 섬을 찾을때까지bfs 돌려본다.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] < 0)
			{
				for (int y = 0; y < n; y++)
				{
					for (int x = 0; x < n; x++)
					{
						copyv[y][x] = visited[y][x];
						copyd[y][x] = d[y][x];
					}
				}
				bfs_build(j, i); // 찾으면 다리 건설 진행

				//for (int i = 0; i < n; i++)
				//{
				//	for (int j = 0; j < n; j++)
				//	{
				//		cout << copyd[i][j] << ' ';
				//	}
				//	cout << '\n';
				//}
				//cout << '\n';
			}
		}
	}

	cout << min_dst;

	return 0;
}