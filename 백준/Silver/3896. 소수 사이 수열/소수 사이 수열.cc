#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);	

	const int sz = 1299709;
	vector<bool> isPrime(sz+1, true);

	for (int i = 2; i * i <= sz; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= sz; j += i)
		{
			isPrime[j] = false;
		}
	}

	vector<int> primes;
	for (int i = 2; i <= sz; i++)
	{
		if (isPrime[i])
			primes.push_back(i);
	}

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		if (isPrime[n])
			cout << "0\n";
		else
		{
			int ub = lower_bound(primes.begin(), primes.end(), n) - primes.begin();
			int lb = ub - 1;
			cout << primes[ub] - primes[lb] << '\n';
		}
	}

	return 0;
}