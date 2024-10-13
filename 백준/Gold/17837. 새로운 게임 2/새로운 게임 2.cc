#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct horse
{
	int y, x, dir;
};
int b[15][15];
vector<int> tower[15][15];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, k;


horse horses[11];

int CounterDir(int cdir)
{
	switch(cdir)
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
bool Move(int ix)
{
	horse h = horses[ix];
	int tx = h.x + dx[h.dir];
	int ty = h.y + dy[h.dir];
	if (tx < 1 || ty <1 || tx >n || ty >n || b[ty][tx] ==2)
	{
		horses[ix].dir = CounterDir(h.dir);
		tx = h.x + dx[horses[ix].dir];
		ty = h.y + dy[horses[ix].dir];
		if (!(tx < 1 || ty <1 || tx >n || ty >n || b[ty][tx] == 2))
		{
			if (b[ty][tx] == 0)
			{
				int loc = find(tower[h.y][h.x].begin(), tower[h.y][h.x].end(), ix) - tower[h.y][h.x].begin();
				for (int i = loc; i < tower[h.y][h.x].size(); i++)
				{
					tower[ty][tx].push_back(tower[h.y][h.x][i]);
					horses[tower[h.y][h.x][i]].x = tx;
					horses[tower[h.y][h.x][i]].y = ty;
				}
				while (tower[h.y][h.x].size() > loc)
				{
					tower[h.y][h.x].pop_back();
				}
			}
			else if (b[ty][tx] == 1) //빨간 칸인경우
			{
				int loc = find(tower[h.y][h.x].begin(), tower[h.y][h.x].end(), ix) - tower[h.y][h.x].begin();
				while (tower[h.y][h.x].size() > loc)
				{
					tower[ty][tx].push_back(tower[h.y][h.x].back());
					horses[tower[h.y][h.x].back()].x = tx;
					horses[tower[h.y][h.x].back()].y = ty;
					tower[h.y][h.x].pop_back();
				}
			}
		}
	}
	else if(b[ty][tx] == 0)
	{
		int loc = find(tower[h.y][h.x].begin(), tower[h.y][h.x].end(), ix) - tower[h.y][h.x].begin();
		for (int i = loc; i < tower[h.y][h.x].size(); i++)
		{
			tower[ty][tx].push_back(tower[h.y][h.x][i]);
			horses[tower[h.y][h.x][i]].x = tx;
			horses[tower[h.y][h.x][i]].y = ty;
		}
		while (tower[h.y][h.x].size() > loc)
		{
			tower[h.y][h.x].pop_back();
		}
	}
	else //빨간 칸인경우
	{
		int loc = find(tower[h.y][h.x].begin(), tower[h.y][h.x].end(), ix) - tower[h.y][h.x].begin();
		while (tower[h.y][h.x].size() > loc)
		{
			tower[ty][tx].push_back(tower[h.y][h.x].back());
			horses[tower[h.y][h.x].back()].x = tx;
			horses[tower[h.y][h.x].back()].y = ty;
			tower[h.y][h.x].pop_back();
		}
	}
	if (tower[ty][tx].size() >= 4)
		return true;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> b[i][j]; 
		}
	}

	for (int i = 1; i <= k; i++)
	{
		int r, c, dir;
		cin >> r >> c >> dir;
		horses[i] = { r,c, dir-1};
		tower[r][c].push_back(i);
	}

	int moved = 0;
	while (moved < 1000)
	{
		moved++;
		for (int i = 1; i <= k; i++)
		{
			if (Move(i))
			{
				cout << moved;
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}