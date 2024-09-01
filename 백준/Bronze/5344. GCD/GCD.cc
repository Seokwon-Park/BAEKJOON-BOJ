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
	while (b)
	{
		ll tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		ll a, b;
		cin >> a >> b;
		cout << gcd(a, b) << '\n';
	}
	return 0;
}
