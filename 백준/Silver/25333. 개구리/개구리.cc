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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, x;
		cin >> a >> b >> x;
		int g = gcd(a, b);
		cout << x / g << '\n';

	}
	
	return 0;
} 