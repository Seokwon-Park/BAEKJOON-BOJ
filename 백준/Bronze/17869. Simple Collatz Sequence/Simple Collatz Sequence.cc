#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

ll A(ll x)
{
	ll cnt = 0;
	while (x != 1)
	{
		if (x % 2)
		{
			x += 1;
		}
		else
		{
			x /= 2;
		}
		cnt++;
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n;
	cin >> n;

	cout << A(n);

	return 0;
}



