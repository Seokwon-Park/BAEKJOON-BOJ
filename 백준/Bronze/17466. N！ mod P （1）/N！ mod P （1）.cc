//https://www.luschny.de/math/factorial/binarysplitfact.html
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int num, per;

int nminussumofbits(int v)
{
	long w = (long)v;
	w -= (0xaaaaaaaa & w) >> 1;
	w = (w & 0x33333333) + ((w >> 2) & 0x33333333);
	w = w + (w >> 4) & 0x0f0f0f0f;
	w += w >> 8;
	w += w >> 16;
	return v - (int)(w & 0xff);
}

ll partProduct(ll n, ll m)
{
	if (m <= (n + 1)) return (ll)n % per;
	if (m == (n + 2)) return (ll)n * m % per;
	ll k = (n + m) / 2;
	if ((k & 1) != 1) k = k - 1;
	return partProduct(n, k) * partProduct(k + 2, m) % per;
}


void loop(ll n, ll& p, ll& r)
{
	if (n <= 2) return;
	loop(n / 2, p, r);
	p = p * partProduct(n / 2 + 1 + ((n / 2) & 1), n - 1 + (n & 1)) % per;
	r = r * p % per;
}

ll Factorial(int n)
{
	ll p = 1, r = 1;
	loop(n, p, r);
	int tmp = nminussumofbits(n);
	while (tmp >= 30)
	{
		r *= 1 << 30;
		r %= per;
		tmp -= 30;
	}
	r <<= tmp;
	r %= per;
	return r;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> num >> per;

	cout << Factorial(num);


	return 0;
}