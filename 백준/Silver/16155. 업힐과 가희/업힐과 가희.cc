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
	vector<pii> v;
	for (int i = 0; i < n+1; i++)
	{
		int x, h;
		cin >> x >> h;
		v.push_back({ x,h });
	}
	ll s, e;
	cin >> s >> e;
	
	ll sn = 0;
	ll sd = 0;
	for (int i = 0; i < n; i++)
	{
		auto [fx, fh] = v[i];
		auto [bx, bh] = v[i + 1];
		if (s <= bx)
		{
			sn= (s - fx) * (bh - fh) + fh * (bx - fx);
			sd = bx - fx; 
			break;
		}
	}

	ll en = 0;
	ll ed = 0;
	for (int i = 0; i < n; i++)
	{
		auto [fx, fh] = v[i];
		auto [bx, bh] = v[i + 1];
		if (e <= bx)
		{
			en = (e - fx) * (bh - fh) + fh * (bx - fx);
			ed = bx - fx;
			break;
		}
	}

	ll l = lcm(sd, ed);
	sn *= l / sd;
	en *= l / ed;
	
	ll nume = abs(en - sn);
	ll deno = l * (e - s);

	if (nume % deno == 0)
	{
		cout << nume / deno;
	}
	else
	{
		ll g = gcd(nume, deno);
		cout << nume / g << '/' << deno / g;
	}

	return 0;
}