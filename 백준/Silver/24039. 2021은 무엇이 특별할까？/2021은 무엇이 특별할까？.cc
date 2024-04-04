#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<bool> isPrime(10005, true);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	isPrime[0] = false;
	isPrime[1] = false;
	vector<int> Primes;
	for (int i = 2; i*i < 10005; i++)
	{
		if (!isPrime[i])continue;
		for (int j = i * i; j < 10005; j += i)
		{
			isPrime[j] = false;
		}
	}
	for (int i = 2; i < 10005; i++)
	{
		if (isPrime[i])
			Primes.push_back(i);
	}
	for (int i = 0; i < Primes.size()-1; i++)
	{
		int res = Primes[i] * Primes[i + 1];
		if (res > n)
		{
			cout << res;
			break;
		}
	}
	
	
	return 0;
}
