#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

ll gcd(ll a, ll b)
{
	int r = a % b;
	while (r)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll r, g;
	cin >> r >> g;

	ll gcdn = gcd(r, g);

	vector<ll> v;
	for (int i = 1; i*i <= gcdn; i++)
	{
		if (gcdn % i == 0)
		{
			if (gcdn / i == i)
			{
				v.push_back(i);
			}
			else
			{
				v.push_back(gcdn / i);
				v.push_back(i);
			}
		}
	}

	sort(v.begin(), v.end());
	for (auto i : v)
	{
		cout << i << ' ' << r / i << ' ' << g / i << '\n';
	}


	return 0;
}
