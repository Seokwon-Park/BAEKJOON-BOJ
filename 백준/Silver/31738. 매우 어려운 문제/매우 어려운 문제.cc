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

	ll n, m;
	cin >> n >> m;

	if (n >= m)
	{
		cout << 0;
	}
	else
	{
		ll ans = 1;
		for (int i = 1; i <= n; i++)
		{
			ans *= i;
			ans %= m;
		}
		cout << ans;
	}



	return 0;
}

