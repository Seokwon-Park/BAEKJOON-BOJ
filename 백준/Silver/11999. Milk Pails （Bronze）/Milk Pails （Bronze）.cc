#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y, m;
	cin >> x >> y >> m;

	int ans = 0;
	for (int i = 0; i*x <= m; i++)
	{
		for (int j = 0; j * y <= m; j++)
		{
			if (i * x + j * y > m) continue;
			ans = max(i * x + j * y, ans);
		}
	}
	cout << ans;

	return 0;
}