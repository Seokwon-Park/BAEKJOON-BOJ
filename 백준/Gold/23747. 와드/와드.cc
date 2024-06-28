#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

char b[1005][1005];
bool v[1005][1005];
int r, c;

void bfs(pii xy, char ch)
{
	queue<pii> q;
	q.push(xy);
	v[xy.second][xy.first] = true;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + ("0121"[i] - '1');
			int ty = y + ("1012"[i] - '1');
			if (tx < 0 || ty < 0 || tx >= c || ty >= r)continue;
			if (v[ty][tx] || b[ty][tx] != ch)continue;
			v[ty][tx] = true;
			q.push({ tx,ty });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> b[i][j];
		}
	}

	int hx, hy;
	cin >> hy >> hx;
	// 1-index -> 0-index;
	hx--;
	hy--;

	string cmd;
	cin >> cmd;

	for (auto c : cmd)
	{
		if (c == 'W')
		{
			bfs({ hx,hy }, b[hy][hx]);
		}
		else if (c == 'L')
			hx--;
		else if (c == 'R')
			hx++;
		else if (c == 'U')
			hy--;
		else
			hy++;
	}

	for (int i = 0; i < 4; i++)
	{
		int tx = hx + ("0121"[i] - '1');
		int ty = hy + ("1012"[i] - '1');
		if (tx < 0 || ty < 0 || tx >= c || ty >= r)continue;
		v[ty][tx] = true;
	}
	v[hy][hx] = true;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (v[i][j])
				cout << '.';
			else
				cout << '#';
		}
		cout << '\n';
	}


	return 0;
}
