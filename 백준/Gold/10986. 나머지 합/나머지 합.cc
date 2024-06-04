#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

ll combination(ll k)
{
	if (k == 0) return 0;
	return k*(k-1LL)/2LL;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m;
	cin >> n >> m;

	vector<ll> v(n + 5);
	vector<ll> pfsum(n + 5);
	vector<ll> left(n + 5);

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		pfsum[i] = pfsum[i - 1] + v[i];
		left[pfsum[i] % m]++;
	}

	ll ans = left[0];

	for (int i = 0; i < m; i++)
	{
		ans += combination(left[i]);
	}

	cout << ans;
	
	return 0;
}