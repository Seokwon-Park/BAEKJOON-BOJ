#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y;
	cin >> x >> y;
	
	vector<pii> xy(3);
	for (int i = 0; i < 3; i++)
	{
		int xx, yy;
		cin >> xx >> yy;
		xy[i] = { xx, yy };
	}

	vector<int> order = { 0,1,2 };

	int ans = INF;
	do
	{
		int cx = x;
		int cy = y;
		double res = 0;
		for (int i = 0; i < order.size(); i++)
		{
			auto [tx, ty] = xy[order[i]];
			int xdiff = tx - cx;
			int ydiff = ty - cy;
			res += sqrt(xdiff * xdiff + ydiff * ydiff);
			cx = tx;
			cy = ty;
		}
		ans = min(ans, (int)res);
	} while (next_permutation(order.begin(), order.end()));

	cout << ans;

	return 0;
}

