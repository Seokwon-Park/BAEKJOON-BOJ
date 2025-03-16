#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

ll a[5005];
ll b[5005];
ll prea[5005];
ll preb[5005];
ll dpa[5005];
ll dpb[5005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		prea[i] = prea[i - 1] + a[i];
		dpa[i] = LLONG_MAX;
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		preb[i] = preb[i - 1] + b[i];
		dpb[i] = LLONG_MAX;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			dpa[j - i] = min(dpa[j-i] ,prea[j] - prea[i]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			dpb[j - i] = min(dpb[j - i], preb[j] - preb[i]);
		}
	}

	ll ans = LLONG_MAX;
	for (int i = 0; i <= n; i++)
	{
		// i + j = 2*n - k; 가 최소가 되도록
		int j = n * 2 - k - i;
		if (j <0 || j > n) continue;
		ans = min(ans, max(dpa[i], dpb[j]));
	}
	cout << ans;

	return 0;
}