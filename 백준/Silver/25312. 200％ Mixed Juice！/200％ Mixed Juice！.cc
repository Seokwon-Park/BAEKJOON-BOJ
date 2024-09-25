#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b)
{
	if(b == 0) return a;
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

	ll n, m;
	cin >> n >> m;

	vector<pair<ll, ll>> wv(n);
	for (int i = 0; i < n; i++)
	{
		ll w, v;
		cin >> w >> v;
		wv[i] = { w,v };
	}
	sort(wv.begin(), wv.end(), [](auto a, auto b) 
		{
			return a.second*b.first> b.second*a.first;
		});

	ll leftAmount = m;
	ll totalSugar = 0;
	for (int i = 0; i < n; i++)
	{
		auto [w, v] = wv[i];
		if (w >= leftAmount)
		{
			ll deno = totalSugar * w + v * leftAmount;
			ll nume = w;
			ll g = gcd(deno, nume);
			cout << deno / g << '/' << nume/g;
			break;
		}

		else
		{
			totalSugar += v;
			leftAmount -= w;
		}
	}

	return 0;
}

