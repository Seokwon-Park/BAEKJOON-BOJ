#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int total = 0;
	vector<pii> xy;
	int cx, cy;
	cin >> cx >> cy;
	xy.push_back({ cx,cy });
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		xy.push_back({ x,y });
		total += abs(cx - x) + abs(cy - y);
		cx = x;
		cy = y;
	}

	int ans = INF;
	for (int i = 1; i < n-1; i++)
	{
		int tmp = total;
		auto [x, y] = xy[i];
		auto [px, py] = xy[i - 1];
		auto [nx, ny] = xy[i + 1];
		tmp -= abs(px - x) + abs(py - y) + abs(nx - x) + abs(ny - y);
		tmp += abs(px - nx) + abs(py - ny);
		ans = min(ans, tmp);
	}
	cout << ans;

	return 0;
}