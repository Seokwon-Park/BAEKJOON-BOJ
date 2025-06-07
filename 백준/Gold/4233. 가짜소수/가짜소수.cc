#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

ll exp(int a, int p)
{
	ll res = 1;
	ll aa = a;
	ll tmp = p;
	while (tmp)
	{
		if (tmp % 2)
		{
			res *= aa;
			res %= p;
		}
		tmp /= 2;
		aa *= aa;
		aa %= p;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int p, a;

	while (1)
	{
		cin >> p >> a;
		if (p == 0 && a == 0) break;

		bool isPrime = true;
		for (int i = 2; i * i <= p; i++)
		{
			if (p % i == 0)
			{
				isPrime = false;
			}
		}

		ll res = exp(a, p);
		cout << (res == a && isPrime == false ? "yes" : "no") << '\n';
	}

	return 0;
}