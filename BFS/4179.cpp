#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

string board[1002];
int fire[1002][1002];
int mover[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int r, c;
	cin >> r >> c;

	//맵을 -1로 초기화
	for (int i = 0; i < r; i++)
	{
		fill(fire[i], fire[i] + c, -1);
		fill(mover[i], mover[i] + c, -1);
	}

	for (int i = 0; i < r; i++)
	{
		cin >> board[i];//열은 string으로 하기때문에 row로만 입력받는다
	}

	queue<pair<int, int>> q1;//불의 bfs
	queue<pair<int, int>> q2;//지훈이의 bfs

	//불과 지훈이의 스타팅 지점을 찾아 각각 시간을 0으로 설정하고 각 queue 에 넣어준다.
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 'F')
			{
				q1.push({ i,j });
				fire[i][j] = 0;
			}
			if (board[i][j] == 'J')
			{
				q2.push({ i,j });
				mover[i][j] = 0;
			}
		}
	}

	
	while (!q1.empty())
	{
		pair<int, int> pos = q1.front();
		q1.pop();
		for (int i = 0; i < 4; i++)//4방향에 대해 bfs
		{
			int tx = pos.X + dx[i];
			int ty = pos.Y + dy[i];
			if (tx < 0 || tx >= r || ty < 0 || ty >= c)//불이 맵밖으로 나가면 안됨
				continue;
			if (fire[tx][ty]>=0 || board[tx][ty] == '#')//이미 불이 번진 곳이나 벽인 경우
				continue;
			//이동하기(불이 번지기) 이전 fire가 도달하는데 걸린시간을 가져와 +1 을 해준다.
			fire[tx][ty] = fire[pos.X][pos.Y]+1;
			//탐색할 위치에 넣는다.
			q1.push({ tx, ty });

		}
	}
	while (!q2.empty())
	{
		pair<int, int> pos = q2.front();
		q2.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = pos.X + dx[i];
			int ty = pos.Y + dy[i];
			if (tx < 0 || tx >= r || ty < 0 || ty >= c)//맵의 끝에 도달했으니까 다음위치가 맵의 밖으로 추정됨(탈출)
			{
				cout << mover[pos.X][pos.Y] + 1;//현재 위치에서 한번 더움직이면 탈출하니깐 시간에 +1
				return 0;
			}
			if (mover[tx][ty] >= 0 || board[tx][ty] == '#')//fire와 동일
				continue;
			if (fire[tx][ty] != -1 && fire[tx][ty] <= mover[pos.X][pos.Y]+1)//만약 지훈이가 다음위치로 가는데 걸리는 "시간(+1)"이 다음위치에 이미 불이 번지는데 시간보다 오래걸리면 이동불가능
				continue;
			//탐색 계속
			mover[tx][ty] = mover[pos.X][pos.Y] + 1;
			q2.push({ tx, ty });

		}
	}
	cout << "IMPOSSIBLE";
	//중간에 return으로 종료되지 못했다면 여기에 도달(탈출 실패)
	return 0;
}
