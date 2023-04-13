#include <bits/stdc++.h>

using namespace std;

int board[128][128];// 대충 2^7 커버가능한 범위
int white, blue;

void recursive(int len, int x, int y)
{	
	int partition = len / 2;
	int checker = board[y][x];
	bool same = true;
	//partition 종이가 모두 같은 수인지 검사
	//만약 checker와 다른 수를 만난 경우 break;
	for (int i = y; i < y + len; i++)
	{
		if (!same) break;
		for (int j = x; j < x + len; j++)
		{
			if (board[i][j] != checker)
			{
				same = false;
				break;
			}
		}
	}
	//모두 같은 종이라면 checker(종이의 가장 왼쪽 위의 값)으로 종이 종류 구분해서 개수 더해줌
	if (same == true)
	{
		if (checker == 0)
			white++;
		if (checker == 1)
			blue++;
		return;
	}
	else
	{
		//아니라면 4개로 파티션해서 다시 돌림
		for (int i = y; i < y+len; i += partition)
			for (int j = x; j < x+len; j += partition)
				recursive(partition, j, i);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
			
	int n;
	cin >> n;
	
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> board[y][x];
		}
	}
	recursive(n, 0, 0);//n 길이의 종이 0, 0에서 시작

	cout << white << '\n' << blue;

	return 0;
}

