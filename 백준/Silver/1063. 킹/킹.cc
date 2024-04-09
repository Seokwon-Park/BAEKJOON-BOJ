#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int dx[8] = { 1,-1,0,0,1,-1,1,-1 }; // R L B T RT LT RB LB
int dy[8] = { 0,0,-1,1,1,1,-1,-1 }; // R L B T RT LT RB LB

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string k, s; // king , stone
	int n;
	cin >> k >> s >> n;

	map<string, int> m;
	m["R"] = 0;
	m["L"] = 1;
	m["B"] = 2;
	m["T"] = 3;
	m["RT"] = 4;
	m["LT"] = 5;
	m["RB"] = 6;
	m["LB"] = 7;

	int kx = k[0] - 'A';
	int ky = k[1] - '1'; // 1-indexed -> 0-indexed
	int sx = s[0] - 'A';
	int sy = s[1] - '1';
	for (int i = 0; i < n; i++)
	{
		string cmd;
		cin >> cmd;
		int dir = m[cmd];
		int tx = kx + dx[dir];
		int ty = ky + dy[dir];
		int stx = 0;
		int sty = 0;
		if (tx < 0 || ty < 0 || tx >= 8 || ty >= 8)continue;
		if (tx == sx && ty == sy)
		{
			stx = sx + dx[dir];
			sty = sy + dy[dir];
			if (stx < 0 || sty < 0 || stx >= 8 || sty >= 8)continue;
			sx = stx;
			sy = sty;
		}
		kx = tx;
		ky = ty;
	}

	cout << char('A'+kx) << char(ky+'1') << '\n';
	cout << char('A'+sx) << char(sy+'1');

	return 0;
}