#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n;
	cin >> n;

	vector<ll> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	ll x;
	cin >> x;
	double total = 0;
	double cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (gcd(x, v[i]) == 1)
		{
			total += v[i];
			cnt++;
		}
	}
	cout << fixed << setprecision(6);
	cout << total / cnt;

	return 0;
}