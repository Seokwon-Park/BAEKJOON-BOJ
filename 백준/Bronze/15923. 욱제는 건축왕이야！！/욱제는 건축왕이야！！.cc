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

	int n;
	cin >> n;
	vector<pii> v(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[i] = { x,y };
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		auto [x, y] = v[i];
		auto [nx, ny] = v[(i + 1)%n];
		ans += abs(nx - x) + abs(ny - y);
	}
	cout << ans;

	return 0;
}
