#include <bits/stdc++.h>

using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	int x = 1000005;
	vector<int> isPrime(x, 1);
	vector<int> primes;
	vector<int> superPrimes(1,0);
	isPrime[1] = 0;
	for (int i = 2; i * i < x; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i * i; j < x; j += i)
		{
			isPrime[j] = 0;
		}
	}

	for (int i = 2; i < x; i++)
	{
		if (isPrime[i])
		{
			primes.push_back(i);
			if(isPrime[primes.size()])
			{
				superPrimes.push_back(i);
				if (superPrimes.size() > 3001) break;
			}
		}
	}

	while (t--)
	{
		int n;
		cin >> n;
		cout << superPrimes[n] << '\n';
	}

	return 0;
}