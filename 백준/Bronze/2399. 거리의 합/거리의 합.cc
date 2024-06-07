#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

ll my_abs(ll n)
{
	if (n < 0)
		return -n;
	return n;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<ll> v(n);
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		for (int j = 0; j < i; j++)
		{
			ans += my_abs(v[i] - v[j]);
		}
	}

	cout << ans*2;

	return 0;
}