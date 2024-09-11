#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

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

	int k, n;
	cin >> k >> n;

	ll res = 1;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		res = lcm(res, m);
	}

	cout << res - k;
	

	return 0;
}

