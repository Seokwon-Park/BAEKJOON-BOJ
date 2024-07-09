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

	int a, b, n, w;
	cin >> a >> b >> n >> w;

	vector<pii> ans;
	for (int x = 1; x < n; x++)
	{
		int y = n - x;
		if (a * x + b * y == w)
			ans.push_back({ x,y });
	}
	if (ans.empty() || ans.size() > 1)
		cout << -1;
	else
		cout << ans[0].first << ' ' << ans[0].second;


	return 0;
}