#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end());
	ll ans = 0;
	for (int i = 0; i < min(m,n); i++)
	{
		ll c = a[i] - b[i];
		if ( c >=0)
		{
			ans += c;
		}
	}
	cout << ans;

	return 0;
}