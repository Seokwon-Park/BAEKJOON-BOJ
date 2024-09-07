#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int sx, sy;
string s;
int dx[4] = { -1,0,1,0 }; 
int dy[4] = { 0,-1,0,1 };

struct state
{
	int x;
	int y;
	string str;
};

unordered_map<string, bool> v;

int bfs(int x, int y)
{
	queue<state> q;
	q.push({ x, y, s });
	v[s] = true;
	int moved = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			state curs = q.front();
			if (curs.str == "123456780")
			{
				return moved;
			}
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int tx = curs.x + dx[i];
				int ty = curs.y + dy[i];
				if (tx < 0 || ty < 0 || tx >= 3 || ty >= 3)continue;
				string tmp = curs.str;
				swap(tmp[ty * 3 + tx], tmp[curs.y * 3 + curs.x]);
				if (v[tmp]) continue;
				q.push({ tx,ty, tmp });
				v[tmp] = true;
			}
		}
		moved++;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 9; i++)
	{
		int j;
		cin >> j;
		if (j == 0)
		{
			sx = i % 3;
			sy = i / 3;
		}
		s += '0' + j;
	}

	cout << bfs(sx, sy);


	return 0;
}
