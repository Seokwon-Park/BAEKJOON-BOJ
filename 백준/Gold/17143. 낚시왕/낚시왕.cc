#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct shark
{
	int x, y, speed, dir, sz;
	bool isDead; // 이걸 넣은 이유는 뒤진 상어는 이동에서 제외하기 위함.
};

shark sharks[10005];

int cur[105][105];
int tmp[105][105];
int h, w, m;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };

int CounterDir(int cdir)
{
	switch (cdir)
	{
	case 0:
		return 1;
	case 1:
		return 0;
	case 2:
		return 3;
	case 3:
		return 2;
	}
}

void MoveSharks()
{
	for (int i = 0; i <= h; i++)
	{
		fill(tmp[i], tmp[i] + w + 1, 0);
	}
	for (int i = 1; i <= m; i++)
	{
		if (sharks[i].isDead) continue;
		int move = sharks[i].speed;
		int x = sharks[i].x;
		int y = sharks[i].y;
		if (sharks[i].dir == 0 || sharks[i].dir == 1)
		{
			move %= (h - 1)*2;

		}
		if (sharks[i].dir == 2 || sharks[i].dir == 3)
		{
			move %= (w - 1)*2;
		}
		while(move--)
		{
			int tx = x + dx[sharks[i].dir];
			int ty = y + dy[sharks[i].dir];
			if (tx <1 || ty <1 || tx>w || ty >h)
			{
				sharks[i].dir = CounterDir(sharks[i].dir);
				int tx = x + dx[sharks[i].dir];
				int ty = y + dy[sharks[i].dir];
				x = tx;
				y = ty;
			}
			else
			{
				x = tx;
				y = ty;
			}
		}
		if (tmp[y][x] == 0)
		{
			tmp[y][x] = i;
		}
		else
		{
			if (sharks[i].sz > sharks[tmp[y][x]].sz)
			{
				sharks[tmp[y][x]].isDead = true;
				tmp[y][x] = i;
			}
			else
			{
				sharks[i].isDead = true;
			}
		}
		if (!sharks[i].isDead)
		{
			sharks[i].x = x;
			sharks[i].y = y;
		}
	}
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			cur[i][j] = tmp[i][j];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> h >> w >> m;
	for (int i = 1; i <= m; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		sharks[i] = { c,r,s,d-1,z, false };
		cur[r][c] = i;
	}

	int ans = 0;
	for (int i = 1; i <=w; i++)
	{
		// 열에서 땅과 가장 가까운 상어 잡기
		for (int j = 1; j <= h; j++)
		{
			if (cur[j][i] != 0) // 만약 열에서 가장 가까운 상어를 만나면(못만날수도있음)
			{
				ans += sharks[cur[j][i]].sz; // 그 크기만큼 정답에 더함
				sharks[cur[j][i]].isDead = true; // 이 상어는 죽음
				//cur[j][i] = 0; // 잠시 보류.
				break;
			}
		}
		//상어 이동
		MoveSharks();
	}

	cout << ans;
	

	return 0;
}
