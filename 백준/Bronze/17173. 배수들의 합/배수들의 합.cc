#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

bool isAdded[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		for (int j = k; j <= n; j += k)
		{
			if (!isAdded[j])
			{
				isAdded[j] = true;
				ans += j;
			}
		}
	}
	cout << ans;

	return 0;
}