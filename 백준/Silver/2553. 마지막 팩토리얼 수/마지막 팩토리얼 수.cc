#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll res = 1;
	for (int i = 1; i <= n; i++)
	{
		res *= i;
		int base = 1e9;
		while (res % 10 == 0)
		{
			res /= 10;
		}
		res %= base;
	}

	cout << res % 10;

	return 0;
}