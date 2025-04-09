#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

ll l[10005];
ll r[10005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll x, k;
	cin >> x >> k;
	for (int i = 0; i < x; i++)
	{
		int n;
		cin >> n;
		l[n]++;
	}
	for (int i = 0; i < x; i++)
	{
		int n;
		cin >> n;
		r[n]++;
	}

	ll ans = 0;
	for (int i = 1; i <= k; i++)
	{
		ans += l[i] * (x - r[i]);
	}
	cout << ans;
	
	return 0;
}