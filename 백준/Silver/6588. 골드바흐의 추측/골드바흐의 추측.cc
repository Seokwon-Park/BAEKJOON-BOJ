#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vec<bool> isPrime(1000005, true);
	for (int i = 2; i * i <= 1000000; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= 1000000; j += i)
		{
			isPrime[j] = false;
		}
	}

	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		int a, b;
		bool find = false;
		for (int i = 3; i <= n / 2; i++)
		{
			if (isPrime[i])
			{
				if (isPrime[n - i])
				{
					a = i;
					b = n - i;
					find = true;
					break;
				}
			}
		}
		if (find)
		{
			cout << n << " = " << a << " + " << b << '\n';
		}
		else
		{
			cout << "Goldbach's conjecture is wrong.\n";
		}

	}

	return 0;
}