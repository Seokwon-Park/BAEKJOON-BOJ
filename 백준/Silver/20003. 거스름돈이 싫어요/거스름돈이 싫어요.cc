#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pii> fraction(n);
	ll total = 1;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		ll g = gcd(a, b);
		if (g != 1)
		{
			a /= g;
			b /= g;
		}
		
		fraction[i] = { a,b };
		total = lcm(total, b);
	}

	for (int i = 0; i < n; i++)
	{
		ll tmp = total / fraction[i].second;
		fraction[i].first *= tmp;
		fraction[i].second = total;
	}

	ll ans = -1;
	for (int i = 0; i < n; i++)
	{
		if (ans == -1)
		{
			ans = fraction[i].first;
		}
		else
		{
			ans = gcd(ans, fraction[i].first);
		}
	}

	ll g = gcd(ans, total);
	cout << ans / g << ' ' << total / g;

	
	



	return 0;
}