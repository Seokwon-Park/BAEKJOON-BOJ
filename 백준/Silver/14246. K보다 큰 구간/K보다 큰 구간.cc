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
	
	int n;
	cin >> n;
	vector<ll>v(n+1);
	vector<ll> pf(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		pf[i] = pf[i - 1] + v[i];
	}

	ll k;
	cin >> k;

	ll ans = 0;
	int st = 0;
	int en = 1;
	while (en <= n)
	{
		if (pf[en] - pf[st] > k)
		{
			ans += n - en + 1;
			st++;
		}
		else
		{
			en++;
		}
	}
	cout << ans;

	return 0;
}