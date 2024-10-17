#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int n;
char b[25][25];
pii p[25][25];
string dirCh = "AWDS";
vector<int> cmd[25];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int sx, sy, ex, ey;
int h, w;

void bfs()
{
	queue<tuple<int,int,string>> q;
	q.push({ sx,sy,""});
	for (int i = 0; i < n; i++) // n번 움직이기
	{
		int qs = q.size();
		for (int j = 0; j < qs; j++)
		{
			int x, y;
			string str;
			tie(x, y, str) = q.front();
			q.pop();
			for (auto k : cmd[i])
			{
				int tx = x + dx[k];
				int ty = y + dy[k];
				string tstr = str+dirCh[k];
				if (tx < 0 || ty < 0 || tx >= w || ty >= h)continue;
				if (b[ty][tx] == '@')continue;
				if (ty == ey && tx == ex)
				{
					cout << "YES\n";
					cout << tstr << '\n';
					return;
				}
				q.push(tie(tx, ty, tstr));

			}
		}
	}
	cout << "NO";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> h >> w;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 'D')
			{
				sx = j;
				sy = i;
			}
			if (b[i][j] == 'Z')
			{
				ex = j;
				ey = i;
			}
		}
	}

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			char ch;
			cin >> ch;
			int dir = 0;
			switch (ch)
			{
			case 'W':
				dir = 1;
				break;
			case 'A':
				dir = 0;
				break;
			case 'S':
				dir = 3;
				break;
			case 'D':
				dir = 2;
				break;
			}
			cmd[i].push_back(dir);
		}
	}

	bfs();
	



	return 0;
}