#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

char b[10][10];
char isVertical[10][10];
char isHorizontal[10][10];
map<char, int>dx;
map<char, int>dy;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		fill(b[i], b[i] + n, '.');
	}

	dx['D'] = 0;
	dx['U'] = 0;
	dx['L'] = -1;
	dx['R'] = 1;

	dy['D'] = 1;
	dy['U'] = -1;
	dy['L'] = 0;
	dy['R'] = 0;

	string cmd;
	cin >> cmd;
	int cx = 0;
	int cy = 0;
	for (auto c : cmd)
	{
		int tx = cx + dx[c];
		int ty = cy + dy[c];
		if (tx < 0 || ty < 0 || tx >= n || ty >= n)continue;
		if (c == 'U' || c == 'D')
		{
			isVertical[cy][cx] = true;
			isVertical[ty][tx] = true;
		}
		else if(c == 'L' || c== 'R')
		{
			isHorizontal[cy][cx] = true;
			isHorizontal[ty][tx] = true;
		}
		if (isVertical[cy][cx] && isHorizontal[cy][cx])
		{
			b[cy][cx] = '+';
		}
		else if (isVertical[cy][cx])
		{
			b[cy][cx] = '|';
		}
		else
		{
			b[cy][cx] = '-';
		}

		if (isVertical[ty][tx] && isHorizontal[ty][tx])
		{
			b[ty][tx] = '+';
		}
		else if (isVertical[ty][tx])
		{
			b[ty][tx] = '|';
		}
		else
		{
			b[ty][tx] = '-';
		}
		cx = tx;
		cy = ty;
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << b[i][j];
		}
		cout << '\n';
	}
	

	return 0;
}