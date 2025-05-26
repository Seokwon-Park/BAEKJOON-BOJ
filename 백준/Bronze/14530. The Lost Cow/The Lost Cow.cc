
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int x, y;
	cin >> x >> y;
	int move = 1;
	int cur = x;
	int d = 0;
	while (true)
	{
		int nxt = x + move;
		if (nxt > cur)
		{
			if (cur < y && nxt >= y)
			{
				d += abs(cur - y);
				break;
			}
		}
		else
		{
			if (cur > y && nxt <= y)
			{
				d += abs(cur - y);
				break;
			}
		}
		d += abs(nxt - cur);
		cur = nxt;
		move *= -2;
	}

	cout << d;

	return 0;
}
