#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}

int bitcount(int x)
{
	x = (x >> 1 & 0x55555555) + (x & 0x55555555);
	x = (x >> 2 & 0x33333333) + (x & 0x33333333);
	x = (x >> 4 & 0x0F0F0F0F) + (x & 0x0F0F0F0F);
	x = (x >> 8 & 0x00FF00FF) + (x & 0x00FF00FF);
	x = (x >> 16 & 0x0000FFFF) + (x & 0x0000FFFF);
	return x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, k;
	cin >> n >> k;
	vector<int> v(k);
	for (int i = 0; i < k; i++)
	{
		cin >> v[i];
	}

	ll m = 0;
	for (int i = 1; i < (1 << k); i++)
	{
		ll l = 1;
		for (int j = 0; j < k; j++)
		{
			if (1 << j & i)
			{
				l = lcm(l, v[j]);
				if (l > n) break;
			}
		}
		if (l > n) continue;
		if (bitcount(i) % 2)
		{
			m += n / l;
		}
		else
		{
			m -= n / l;
		}
	}

	cout << n - m;
	
	return 0;
}