#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> k;

	int n, m = 0;

	if (k % 3 == 0)
	{
		n = k / 3;
	}
	else
	{
		n = k / 3 + 1;
	}

	if (k == 1)
	{
		m = 1;
	}
	else
	{
		while (k % 4 == 0)
		{
			k /= 4;
			m++;
		}
		for (int i = 2; i <= 1000000; i++)
		{
			while (k % i == 0)
			{
				k /= i;
				m++;
			}
		}
	}

	cout << n << ' ' << m;


	return 0;
}