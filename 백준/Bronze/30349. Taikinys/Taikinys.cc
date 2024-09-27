#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	int a, b;
	int x, y;
	cin >> m >> n >> a >> b >> x >> y;
	int ans = INF;

	bool isHit = false;

	//curx, cury;
	for (int cy = 0; cy < n; cy++)
	{
		for (int cx = 0; cx < m; cx++)
		{
			int tx = cx + x;
			int ty = cy + y;
			if (tx < 0 || ty < 0 || tx >= a || ty >= b) continue;
			ans = min(ans, tx + ty);
			isHit = true;
		}
	}

	if (isHit)
		cout << ans;
	else
		cout << "NEPATAIKYS";


	return 0;
}

