#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'009;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, b;
	cin >> n >> b;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	ll ans = 0;
	ll wait = 0;
	for (int i = 0; i < n; i++)
	{
		wait += v[i];
		ans += wait;
		wait = max(0LL, wait - b);
	}
	cout << ans + wait;

	return 0;
}