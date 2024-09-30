#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

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
	
	ll l = 1;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		l = lcm(l, v[i]);
	}

	ll res = 0;
	for (int i = 0; i < n; i++)
	{
		res += l / v[i];
	}

	ll g = gcd(l, res);

	cout << l / g << '/' << res / g;

	


	return 0;
}

