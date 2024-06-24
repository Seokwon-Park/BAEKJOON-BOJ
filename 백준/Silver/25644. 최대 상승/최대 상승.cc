#include <bits/stdc++.h>

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

	int n;
	cin >> n;
	int mn = INT_MAX;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		if (m < mn)
		{
			mn = m;
		}
		else
		{
			ans = max(ans, m - mn);
		}
	}
	cout << ans;

	return 0;
}

