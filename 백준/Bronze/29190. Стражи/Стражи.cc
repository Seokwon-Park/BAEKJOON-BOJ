#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;
	int ans = 0;
	for (int r = 1; r <= n; r++)
	{
		for (int c = 1; c <= m; c++)
		{
			int dist = abs(x - r) + abs(y - c);
			if (dist <= k)
			{
				ans++;
			}
		}
	}
	cout << ans-1;

	return 0;
}