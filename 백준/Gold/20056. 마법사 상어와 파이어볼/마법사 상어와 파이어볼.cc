#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int n, mm, k;
int b[55][55];
int balls[55][55];
int speed[55][55];
int dir[55][55][8];


int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
queue<vector<int>> fb; // fireball

void printb()
{
	cout << "b\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << b[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "balls\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << balls[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "speed\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << speed[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

vector<int> div_vec(int r, int c)
{
	bool hasOdd = false;
	bool hasEven = false;
	for (int i = 0; i < 8; i++)
	{
		if (dir[r][c][i] > 0)
		{
			dir[r][c][i] = 0;
			if (i % 2 == 1)
				hasOdd = true;
			else
				hasEven = true;
		}
		if (hasOdd && hasEven)
			return { 1,3,5,7 };
	}
	return { 0,2,4,6 };
}

void simul()
{
	while(!fb.empty())
	{
		int r, c, m, s, d;
		r = fb.front()[0];
		c = fb.front()[1];
		m = fb.front()[2];
		s = fb.front()[3];
		d = fb.front()[4];
		fb.pop();
		b[r][c] -= m;
		balls[r][c] -= 1;
		speed[r][c] -= s;
		dir[r][c][d]--;
		assert(dir[r][c][d] >= 0);

		int tx = c + dx[d] * s;
		while (tx > n) tx -= n;
		while (tx < 1) tx += n;
		int ty = r + dy[d] * s;
		while (ty > n) ty -= n;
		while (ty < 1) ty += n;

		b[ty][tx] += m;
		balls[ty][tx] += 1;
		speed[ty][tx] += s;
		dir[ty][tx][d]++;
	}
	//printb();


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (balls[i][j] > 1)
			{
				int newm = b[i][j]/5;
				if (newm == 0)
				{
					balls[i][j] = 0;
					b[i][j] = 0;
					speed[i][j] = 0;
					fill(dir[i][j], dir[i][j] + 8, 0);
					continue;
				}
				int news = speed[i][j] / balls[i][j];
				vector<int> res = div_vec(i,j);
				// 메모 : 이거 빼먹어서 틀린듯? 댕청
				fill(dir[i][j], dir[i][j] + 8, 0);
				for (int kk = 0; kk < 4; kk++)
				{
					int r, c, m, s, d;
					r = i;
					c = j;
					m= newm;
					s = news;
					d = res[kk];

					fb.push({ r,c,m,s,d });
					dir[i][j][res[kk]]++;
				}
				balls[i][j] = 4;
				b[i][j] = newm * 4;
				speed[i][j] = news * 4;
			}
			else if(balls[i][j] == 1)
			{
				int newd= -1;
				for (int kk = 0; kk < 8; kk++)
				{
					if (dir[i][j][kk] > 0)
					{
						newd = kk;
						//dir[i][j][kk] = 1;
						break;
					}
				}
				fb.push({ i, j, b[i][j], speed[i][j], newd });
			}
		}
	}
	//printb();

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> mm >> k;

	for (int i = 0; i < mm; i++)
	{
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fb.push({ r,c,m,s,d });
		b[r][c] = m;
		balls[r][c] = 1;
		speed[r][c] = s;
		dir[r][c][d]++;
	}

	//printb();

	for (int i = 0; i < k; i++)
	{
		simul();
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ans += b[i][j];
		}
	}

	cout << ans;

	return 0;
}