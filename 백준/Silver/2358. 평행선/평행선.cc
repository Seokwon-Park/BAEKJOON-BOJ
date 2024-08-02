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

	map<int, int> xGroup;
	map<int, int> yGroup;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		xGroup[x]++;
		yGroup[y]++;
	}

	int ans = 0;
	for (auto xv : xGroup)
	{
		if (xv.second > 1)
			ans++;
	}
	for (auto yv : yGroup)
	{
		if (yv.second > 1)
			ans++;
	}

	cout << ans;
	return 0;
}