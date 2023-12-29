#include <bits/stdc++.h>

using namespace std;

int board[505][505];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, b;
	cin >> n >> m >> b;

	set<int> s;

	int min_time = INT_MAX;
	int max_h = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	int left_block;
	for (int h = 0; h <= 256; h++) // 모든 높이에 대해 조사해본다.
	{
		bool enoughB = true;
		int t = 0; // 경과 시간
		int curB = b; // 현재 블록
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int diff;
				if (board[i][j] == h) continue; // 높이 같으면 아무것도 안한다.
				else if (board[i][j] < h) //만약 높이가 더 커서 메꿔야 하는경우
				{
					diff = h - board[i][j];
					curB -= diff; // 현재 블록에서 필요한 블록만큼 쓴다.
					t += diff; // 이 작업은 1초가 걸린다.
				}
				else // 만약 board에서 파내야 하는경우
				{
					diff = board[i][j] - h;
					curB += diff; // 파낸 블록만큼 추가
					t += diff * 2; // 2초 걸린다.
				}

			}
		}
		//탐색이 끝났다. 만약 남은 블록이 음수라면 얘는 고르기 못한다는 뜻.
		if (curB < 0)continue;
		else
		{
			if (t < min_time) // 시간이 최소인 값이 있으면 그 시간과 높이로 변경
			{
				min_time = t;
				max_h = h;
			}
			else if (t == min_time) // 만약 시간이 같이 걸렷다면 높이가 더 높은쪽으로
			{
				if (h > max_h)
				{
					max_h = h;
				}
			}
		}	
	}

	cout << min_time << ' ' << max_h;

	return 0;
}
