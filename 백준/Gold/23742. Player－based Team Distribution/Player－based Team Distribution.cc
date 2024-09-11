#include<bits/stdc++.h>

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
	vector<ll> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		
	}
	sort(v.begin(), v.end());
		
	vector<ll> pfsum(n + 1);
	int ix = 1;
	for (int i = 1; i <= n; i++)
	{
		pfsum[i] = pfsum[i - 1] + v[i-1];
		if (v[i-1] < 0)
			ix++;
	}


	ll ans = (pfsum[n] - pfsum[ix - 1]) * (n - ix + 1) + pfsum[ix-1];
	for (int i = 1; i <= n; i++)
	{
		if (v[i - 1] >= 0) break;
		ll res = (pfsum[n] - pfsum[i - 1]) * (n - i + 1) + pfsum[i - 1];
		ans = max(ans, res);
	}

	cout << ans;

	return 0;
}

