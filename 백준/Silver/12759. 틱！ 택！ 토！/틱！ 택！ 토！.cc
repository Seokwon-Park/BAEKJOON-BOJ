#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int b[4][4];

bool check(int r, int c, int st)
{	
	int cnt = 0;
	for (int i = 1; i <= 3; i++)
	{
		if (b[r][i] == st)
			cnt++;
	}
	if (cnt == 3) return true;
	cnt = 0;
	for (int i = 1; i <= 3; i++)
	{
		if (b[i][c] == st)
			cnt++;
	}
	if (cnt == 3) return true;
	if (r == c)
	{
		cnt = 0;
		for (int i = 1; i <= 3; i++)
		{
			if (b[i][i] == st)
				cnt++;
		}
		if (cnt == 3) return true;
	}
	if (r +c == 4)
	{
		cnt = 0;
		for (int i = 1; i <= 3; i++)
		{
			if (b[4-i][i] == st)
				cnt++;
		}
		if (cnt == 3) return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int st;
	cin >> st;
	for (int i = 0; i < 9; i++)
	{
		int r, c;
		cin >> r >> c;
		b[r][c] = st;
		if (check(r, c, st))
		{
			cout << st;
			return 0;
		}
		st = (st - 1 ? 0 :1 ) + 1;
	}

	cout << 0;
	return 0;
}