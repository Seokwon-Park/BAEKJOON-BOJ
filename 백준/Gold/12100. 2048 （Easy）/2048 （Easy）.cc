#include <bits/stdc++.h>

using namespace std;

int n;
int board[25][25];
int copyb[25][25];

void rotate()
{
	int tmp[25][25];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = copyb[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			copyb[j][n-i-1] = tmp[i][j];
}

void tilt(int dir)
{
	while (dir--) rotate();
	for (int i = 0; i < n; i++)
	{
		vector<int> tilted(n, 0);
		int ix = 0; // tilted에 다음 값이 들어갈 위치를 지정하는 포인터
		for (int j = 0; j < n; j++)
		{
			if (!copyb[i][j])continue; // 만약 i번 라인의 j번째 수가 0이면 스킵한다.
			if (tilted[ix] == 0) // 만약 tilted[ix]가 0이면 비어있으므로
			{
				tilted[ix] = copyb[i][j]; // 값을 넣어준다.
			}
			else // 만약 tilted[ix]에 어떤 값이 들어가 있으면
			{
				if (tilted[ix] == copyb[i][j]) // 왼쪽으로 밀어줄 값과 같으면
				{
					tilted[ix++] *= 2; // 2배로 만들고 다음 위치로 포인터를 옮긴다. (합쳐지고 또 합쳐지기 안됨)
				}
				else // 왼쪽으로 밀어줄 값과 다르면
				{
					tilted[++ix] = copyb[i][j]; // 먼저 포인터를 옮기고 값을 대입한다. (합쳐지지 않음)
				}
			}
		}
		for (int j = 0; j < n; j++) //i번 라인에 대해 기울임이 완료된 값으로 board를 갱신한다.
		{
			copyb[i][j] = tilted[j];
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	int answer = INT_MIN;
	int ff = 1 << 10;// 2^10 = 4^5 
	//5자리 4진수에 대해서 모든 경우의 수를 조사하는 것임.
	for (int b = 0; b < ff; b++)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				copyb[i][j] = board[i][j];
		int bf = b;
		for (int i = 0; i < 5; i++)
		{
			int dir = bf % 4;
			bf /= 4;
			tilt(dir);
		}
		//5번 다 기울이고 나서 board에서 최댓값을 뽑는다.
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				answer = max(answer, copyb[i][j]);
	}
	cout << answer;

	return 0;
}