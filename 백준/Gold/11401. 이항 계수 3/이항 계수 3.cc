#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

using ll = long long;

ll Pow(ll a, ll b)
{
	if (b == 0)
		return 1;
	ll value = Pow(a, b / 2)% MOD;
	value = (value * value) % MOD;
	if (b % 2 == 0)
	{
		return value;
	}
	else 
		return (value*a)% MOD;

}

ll inv(ll n)
{
	// 페르마의 소정리 기억하려고 달아놓은 주석
	// if p is prime, a^p mod p = a mod p;
	// then a^p * a^-1 mod p = a * a^-1 mod p
	// a^ p-1 mod p = 1 mod p
	// n!으로 나눠야 하므로 n^-1 * n-1^-1 * n-2 ^-1.... 이런식으로 구해야 되기 때문에
	// n, n-1, n-2에 대한 모듈러의 역을 구해서 곱하고 곱할때마다 MOD로 또 나누면 n! mod p의 분모를 구할수 있다.
	return Pow(n, MOD - 2) % MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	ll u = 1;
	ll d = 1;

	for (ll i = n - k + 1; i <= n; i++)
	{
		u = (u * i) % MOD;
	}

	for (ll r = k; r >= 1; r--)
	{
		d = (d * inv(r)) % MOD;
	}

	cout << (u * d) % MOD << endl;

	return 0;
}