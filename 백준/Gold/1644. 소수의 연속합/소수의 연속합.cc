#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

vector<bool> isPrime(4000005, true);
vector<int> primes;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	isPrime[1] = false;
	for (int i = 2; i * i <= n; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= n; j += i)
		{
			isPrime[j] = false;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (isPrime[i])
			primes.push_back(i);
	}

	if (primes.size() < 2)
	{
		cout << primes.size();
		return 0;
	}
	int st = 0;
	int ed = 1;
	int res = primes[st]+primes[ed];
	int ans = 0;
	if (isPrime[n])ans++;
	while (ed < primes.size() && st < ed)
	{
		if (res < n)
		{
			ed++;
			res += primes[ed];
		}
		else if (res > n)
		{
			res -= primes[st];
			st++;
		}
		else
		{
			ans++;
			ed++;
			res += primes[ed];
		}
	}

	cout << ans;


	return 0;
}