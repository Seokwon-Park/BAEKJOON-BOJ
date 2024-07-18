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

	int n, b, h, w;
	cin >> n >> b >> h >> w;
	int ans = INF;
	for (int i = 0; i < h; i++)
	{
		int p;
		cin >> p;
		int limit = 0;
		for (int j = 0; j < w; j++)
		{
			int m;
			cin >> m;
			if (m > limit) limit = m;
		}
		if (limit >= n && p * n <= b)
		{
			ans = min(ans, p * n);
		}
	}
	if (ans == INF)
		cout << "stay home";
	else
		cout << ans;

	return 0;
}