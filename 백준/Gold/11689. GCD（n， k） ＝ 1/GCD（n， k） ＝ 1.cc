#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int pow(int n, int exp)
{
	int ret = 1;
	for (int i = 0; i < exp; i++)
	{
		ret *= n;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;
	
	ll ans = 1;
	for (ll i = 2; i*i <= n; i++)
	{
		if (n % i != 0)continue;
		int exp = 0;
		while (n % i == 0)
		{
			n /= i;
			exp++;
		}
		ans *= (pow(i, exp) - pow(i, exp - 1));
	}
	if (n != 1)
	{
		ans *= (pow(n, 1) - pow(n, 0));
	}

	cout << ans;
	

	return 0;
}
