#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
//const int MOD = 1'000'000'007;
const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

bool isPrime[1000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	fill(isPrime, isPrime + n + 5, true);

	isPrime[1] = false;
	vector<ll> primes;
	for (ll i = 2; i * i <= n; i++)
	{
		if (isPrime[i] == false) continue;
		for (ll j = i * i; j <= n; j += i)
		{
			isPrime[j] = false;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (isPrime[i]) primes.push_back(i);
	}

	vector<int> exps(n + 5);
	vector<ll> mem(n + 5);
	for (auto prime : primes)
	{
		ll x = prime;
		int exp = 1;
		while (x * prime <= n)
		{
			exp++;
			x *= prime;
		}
		if (exps[prime] < exp)
		{
			exps[prime] = exp;
			mem[prime] = x % MOD;
		}
	}

	ll result = 1;
	for (int i = 0; i <= n; i++)
	{
		if (exps[i] > 0)
		{
			result *= mem[i];
			result %= MOD;
		}
	}
	cout << result;

	return 0;
}