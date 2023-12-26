#include <bits/stdc++.h>

#define X first;
#define Y second;

using namespace std;

int sdoku[9][9];
bool isused[10];
vector<pair<int, int>> posXY;
bool isFin;

bool chkrow(int y)
{
	for (int i = 0; i < 9; i++)
	{
		if (isused[sdoku[y][i]] && sdoku[y][i] != 0)
		{
			fill(isused, isused+10, false);
			return false;
		}
		isused[sdoku[y][i]] = true;
	}
	fill(isused, isused+10, false);
	return true;
}

bool chkcol(int x)
{
	for (int i = 0; i < 9; i++)
	{
		if (isused[sdoku[i][x]] && sdoku[i][x] != 0)
		{
			fill(isused, isused+10, false);
			return false;
		}
		isused[sdoku[i][x]] = true;
	}
	fill(isused, isused+10, false);
	return true;
}

bool chk3x3(int x, int y)
{
	int sx = x / 3;
	int sy = y / 3;
	for (int i = sy*3; i < sy*3+3; i++)
	{
		for (int j = sx*3; j < sx*3+3; j++)
		{
			if (isused[sdoku[i][j]] && sdoku[i][j] != 0)
			{
				fill(isused, isused+10, false);
				return false;
			}
			isused[sdoku[i][j]] = true;
		}
	}
	fill(isused, isused+10, false);
	return true;
}

void func(int n)
{
	if (n == posXY.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << sdoku[i][j] << ' ';
			}
			cout << '\n';
		}
		isFin = true;
		return;
	}
	
	int x = posXY[n].X;
	int y = posXY[n].Y;
	for (int i = 1; i <= 9; i++) //0인 칸에 대해 1~9씩 대입해본다.
		//만약 i를 대입했는데 chk함수들에서 false를 받는 부분이 있으면 이 숫자는 해당 칸에 들어갈 수 없다는 뜻.
		// 다해봤는데 안되면? 이전 거로 다시 돌아가야 함
	{
		if (isFin) return;
		sdoku[y][x] = i;
		if (!chkrow(y)) continue;
		if (!chkcol(x)) continue;
		if (!chk3x3(x, y)) continue;
		// 다 통과했으면 다음 posXY(해당 칸의 값이 0인 포지션으로 갈수 있게 n+1을 대입해준다.
		func(n + 1);
	}
	sdoku[y][x] = 0;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> sdoku[i][j];
			if (sdoku[i][j] == 0)
			{
				posXY.push_back({ j,i });
			}
		}
	}

	func(0);

	return 0;
}