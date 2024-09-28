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

	int a, b;
	cin >> a >> b;
	a *= 2;
	if (b == 0)
	{
		int x1 = 0;
		int x2 = -a;
		if (x1 == x2)
		{
			cout << 0;
			return 0;
		}
		if (x1 > x2)
			swap(x1, x2);
		cout << x1 << ' ' << x2;
	}
	else
	{
		for (int i = 1; i <= abs(b); i++)
		{
			if (b % i == 0)
			{
				int x1 = i;
				int x2 = b / i;
				if (x1 + x2 == a)
				{
					if (x1 == x2)
					{
						cout << -x1;
						return 0;
					}
					if (-x1 > -x2)
						swap(x1, x2);
					cout << -x1 << ' ' << -x2;
					return 0;
				}
			}
		}
	}

	return 0;
}