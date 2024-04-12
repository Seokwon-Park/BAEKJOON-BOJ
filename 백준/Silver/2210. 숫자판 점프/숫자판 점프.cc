#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int b[5][5];
string tmp;
set<string> s;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void func(int x, int y, int k)
{
	if (k == 6)
	{
		s.insert(tmp);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx >= 5 || ty >= 5)continue;
		tmp.push_back(b[y][x]);
		func(tx, ty, k+1);
		tmp.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			func(j, i, 0);
		}
	}

	cout << s.size();
	
	return 0;
}
