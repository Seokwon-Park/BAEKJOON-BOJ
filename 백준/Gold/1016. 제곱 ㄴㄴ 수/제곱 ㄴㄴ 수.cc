#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

vector<bool> isPrime(2000005, 1);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;

	ll limit = sqrt(b);
	for (ll i = 2; i * i <= limit; i++)
	{
		if (!isPrime[i]) continue;
		for (ll j = i * i; j <= limit; j += i)
		{
			isPrime[j] = 0;
		}
	}

	vector<ll> primes;
	for (ll i = 2; i * i <= b; i++)
	{
		if (isPrime[i]) primes.push_back(i);
	}

	ll res = b - a + 1;
	vector<bool> isNono(res, 1);
	
	for (ll i : primes)
	{
		ll k = i * i;
		ll st = a / k * k;
		if (st < a) st += k;
		for (ll j = st; j <= b; j+=k)
		{
			isNono[j - a] = 0;
		}
	}
	

	cout << count(isNono.begin(), isNono.end(), 1);

	return 0;
}
