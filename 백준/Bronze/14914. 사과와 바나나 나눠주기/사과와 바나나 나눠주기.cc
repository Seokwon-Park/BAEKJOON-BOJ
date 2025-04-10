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
	
	int a, b;
	cin >> a >> b;
	int res = gcd(a, b);

	for (int i = 1; i <= res; i++)
	{
		if (res % i == 0)
		{
			cout << i << ' ' << a / i << ' ' << b / i << '\n';
		}
	}



	return 0;
}
