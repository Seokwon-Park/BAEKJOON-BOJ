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

	ll n;
	cin >> n;
	
	ll tmp = n;
	ll p = 1;
	while (p <= n)
	{
		p <<= 1LL;
	}

	p -= 1;
	if (p == n)
	{
		cout << 1 << '\n';
		cout << n;
	}
	else
	{
		cout << 2 << '\n';
		cout << p - n << '\n' << n;
	}




	return 0;
}