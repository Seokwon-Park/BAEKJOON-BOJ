#include<bits/stdc++.h>
using namespace std;

int top[5][8];
bool ischanged[5];

void rotate_c(int ix)
{
	int last = top[ix][7];
	for (int i = 7; i >= 1; i--)
	{
		top[ix][i] = top[ix][i - 1];
	}
	top[ix][0] = last;
}

void rotate_cc(int ix)
{
	int first = top[ix][0];
	for (int i = 0; i < 7; i++)
	{
		top[ix][i] = top[ix][i + 1];
	}
	top[ix][7] = first;
}

void rotate(int ix, int dir)
{
	if (dir == 1) rotate_c(ix);
	else rotate_cc(ix);
}

void checklr(int ix, int dir)
{
	ischanged[ix] = true;
	if (ix - 1 >= 1 && ischanged[ix - 1] == false) // 
	{
		if (top[ix - 1][2] != top[ix][6]) // 만약 왼쪽 톱니가 돌아야 한다면,
		{
			checklr(ix - 1, -dir); // 왼쪽 톱니의 왼쪽 톱니도 돌아야 되는지 확인해야된다.
			//rotate(ix - 1, -dir);
			rotate(ix - 1, -dir); // 확인 했으면 현재 톱니의 반대 방향으로 돌려준다.
		}
	}
	if (ix + 1 <= 4 && ischanged[ix + 1] == false)
	{
		if (top[ix + 1][6] != top[ix][2])
		{
			checklr(ix + 1, -dir); // 양옆으로 돌아야 하는지 확인한다.
			//rotate(ix + 1, -dir);
			rotate(ix + 1, -dir);
		}
	}
	ischanged[ix] = false;
}

//index = 0 : 12시 | = 2: 3시 | = 4 : 6시 | = 6: 9시
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char c;
			cin >> c;
			top[i][j] = c - '0';
		}
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int ix, dir;
		cin >> ix >> dir;
		checklr(ix, dir); // 양옆의 톱니에 대해서 회전이 필요하면 적용한다.
		rotate(ix, dir); // 처음선택한 톱니에 대해서 회전을 적용한다.
	}

	int answer = 0;
	int bi = 1;
	for (int i = 1; i <= 4; i++)
	{
		if (top[i][0])
		{
			answer += bi * top[i][0];
		}
		bi *= 2;
	}

	cout << answer;

	return 0;
}