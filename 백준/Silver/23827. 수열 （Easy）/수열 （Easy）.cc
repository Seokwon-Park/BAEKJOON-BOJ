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
	vector<ll> pfsum(n+1);
	vector<ll> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		pfsum[i] = pfsum[i - 1] + v[i];
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += v[i] * (pfsum[n] - pfsum[i]);
		ans %= MOD;
	}
	cout << ans;

	return 0;
}