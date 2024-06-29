#include <bits/stdc++.h>

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
	
	ll n;
	cin >> n;

	ll tmp = n;

	if (n % 2 == 0)
	{
		tmp--;
	}
	ll ans = 1;
	while (tmp > 0)
	{
		ans *= tmp;
		tmp -= 2;
	}

	cout << ans;

	return 0;
}