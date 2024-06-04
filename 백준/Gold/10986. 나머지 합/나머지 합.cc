#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m;
	cin >> n >> m;

	vector<ll> v(n + 5);
	vector<ll> left(m);

	ll pfsum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		pfsum += v[i];
		left[pfsum % m]++;
	}

	ll ans = left[0];

	for (int i = 0; i < m; i++)
	{
		ans += left[i] * (left[i] - 1LL) / 2LL;
	}

	cout << ans;
	
	return 0;
}