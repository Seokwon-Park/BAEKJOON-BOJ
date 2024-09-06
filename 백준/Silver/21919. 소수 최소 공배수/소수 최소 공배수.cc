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
	if (b == 0)return a;
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

	vector<bool> isPrime(1000005, true);

	isPrime[1] = false;
	for (int i = 2; i * i <= 1000000; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= 1000000; j += i)
		{
			isPrime[j] = false;
		}
	}

	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		if (isPrime[m])
			v.push_back(m);
	}

	ll ans = 1;
	for (int i = 0; i < v.size(); i++)
	{
		ans = lcm(ans, v[i]);
	}
	if (v.empty())
		cout << -1;
	else
		cout << ans;

	return 0;
}
