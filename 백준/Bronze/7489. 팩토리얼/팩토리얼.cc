#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int Primes[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		fill(Primes, Primes + 1005, 0);
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			int tmp = j;
			for (int i = 2; i <= j; i++)
			{
				while (tmp % i == 0)
				{
					tmp /= i;
					Primes[i]++;
				}
			}
		}

		if (Primes[2] > Primes[5])
		{
			Primes[2] -= Primes[5];
			Primes[5] = 0;
		}
		else
		{
			Primes[5] -= Primes[2];
			Primes[2] = 0;
		}

		int res = 1;
		for (int i = 0; i <= 1001; i++)
		{
			if (Primes[i] > 0)
			{
				for (int j = 0; j < Primes[i]; j++)
				{
					res = (res*i) %10;
				}
			}
		}
		cout << res %10<< '\n';
	}
	

	return 0;
}
