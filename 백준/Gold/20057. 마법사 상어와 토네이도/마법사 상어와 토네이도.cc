#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int b[505][505];
int test[505][505];
int n;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int blow[5][5] =
{
	{0 ,0, 2, 0, 0},
	{0 ,10, 7, 1, 0},
	{5 ,0, 0, 0, 0},
	{0 ,10, 7, 1, 0},
	{0 ,0, 2, 0, 0},
};

int rCopy[5][5];

int answer = 0;

void rotate()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			rCopy[i][j] = blow[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			blow[4-j][i] = rCopy[i][j];
		}
	}
}

void wind(int x, int y, int dir)
{
	int a = b[y][x];
	for (int i = y-2; i <= y+2; i++)
	{
		for (int j = x-2; j <= x+2; j++)
		{
			if (y == i && x == j) continue;
			int res = b[y][x] * blow[i - y + 2][j - x + 2] / 100;

			a -= res;
			if (i < 0 || j < 0 || i >= n || j >= n)
			{
				answer += res;
			}
			else
			{
				b[i][j] += res;
			}
		}
	}
	int tx = x + dx[dir];
	int ty = y + dy[dir];
	if (ty >= 0 && tx >= 0 && ty < n && tx < n)
		b[y + dy[dir]][x + dx[dir]] += a;
	else
		answer += a;
	b[y][x] = 0;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}
	int x = n / 2;
	int y = n / 2;
	int dir = 0;
	int go = 1;
	int rotated = 0;
	int moved = 0;
	int t = 0;
	while (x != 0 || y != 0)
	{
		//test[y][x] = t++;
		if (moved == go)
		{
			//rotate;
			dir = (dir + 3) % 4;
			rotate();
			rotated++;
			moved = 0;
		}
		if (rotated == 2)
		{
			rotated = 0;
			go++;
		}
		
		int tx = x + dx[dir];
		int ty = y + dy[dir];
		wind(tx, ty, dir);
		moved++;
		x = tx;
		y = ty;
	}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout <<test[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	cout << answer;



	return 0;
}
