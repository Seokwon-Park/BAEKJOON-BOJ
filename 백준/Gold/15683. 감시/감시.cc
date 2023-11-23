#include <bits/stdc++.h>

using namespace std;

int dx[4] = { 1,0,-1,0 }; //x
int dy[4] = { 0,1,0,-1 }; //y
int n, m;
int board[10][10]; // 그림
int board2[10][10];
vector<pair<int, int>> cctvs;

void watch(int x, int y, int dir)
{
	dir %= 4;
	while (1)
	{
		x += dx[dir];
		y += dy[dir];
		if ((x < 0 || y < 0 || x >= n || y >= m) || board2[x][y] == 6) return; // out of bounds나 벽을 만나면 return;
		if (board2[x][y] != 0) continue;
		board2[x][y] = 7;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int mn = 0;
	//여기서 board에 정보 입력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != 6)// 만약 벽이나 빈공간이 아니면 cctv
			{
				cctvs.push_back({ i, j });// cctv 배열에 cctv의 좌표 저장
			}
			if (board[i][j] == 0) mn++; // 입력된 값에서 감시안되는 영역 넓이 저장
		}
	}

	for (int four = 0; four < (1 << (cctvs.size() * 2)); four++) // 4진법으로 4방향을 감시
	//(cctvs.size * 2)하는 이유는 1<< 2진법을 4진법으로 바꾸기 위해서 2^(cctv.size()*2) = 4^cctv.size()이므로
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				board2[i][j] = board[i][j];//감시영역을 그리기 위해 board2에 원본 맵을 복사
				//(모든 경우마다 원본 board에서 그리기 시작해야 하기때문에)
			}
		}
		int tmp = four;
		for (int j = 0; j < cctvs.size(); j++) // for (int i = 0; i < 1 << (cctvs.size() * 2); i++)  에 의해 
		//000, 001, 002... 333 까지 다 돌려보게 된ㄷr. 이 경우의 수를 카메라마다 적용해주기 위해서 4로 나눈 나머지로 카메라 방향을 정하고 
		//4진법이기 때무에 4로 나누면 다음 순서의 카메라 방향을 얻을수 있다.
		{
			int dir = tmp % 4;
			tmp /= 4;
			int x = cctvs[j].first;
			int y = cctvs[j].second;
			if (board[x][y] == 1)
			{
				watch(x, y, dir);
			}
			else if (board[x][y] == 2)
			{
				watch(x, y, dir);
				watch(x, y, dir+2);
			}
			else if (board[x][y] == 3)
			{
				watch(x, y, dir);
				watch(x, y, dir + 1);
			}
			else if (board[x][y] == 4)
			{
				watch(x, y, dir);
				watch(x, y, dir + 1);
				watch(x, y, dir + 2);
			}
			else if (board[x][y] == 5)
			{
				watch(x, y, dir);
				watch(x, y, dir + 1);
				watch(x, y, dir + 2);
				watch(x, y, dir + 3);
			}				
		}
		int value = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board2[i][j] == 0) value++; // board2에서 감시안되는 영역 넓이 저장
			}
		}
		mn = min(mn, value);
	}

	cout << mn;

	return 0;
}