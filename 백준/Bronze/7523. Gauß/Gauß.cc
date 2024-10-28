#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

ll sum(ll n)
{
	return n * (n + 1) / 2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for(int i = 1; i<= tc;i ++)
	{
		ll n, m;
		cin >> n >> m;
		cout << "Scenario #" << i << ":\n";
		if (n * m < 0)
		{
			if (abs(n) > m)
			{
				cout << -(sum(abs(n)) - sum(m));
			}
			else
			{
				cout << sum(m) - sum(abs(n));
			}
		}
		else
		{
			if (abs(n) > abs(m))
			{
				cout << -(sum(abs(n)) - sum(abs(m)-1));
			}
			else
			{
				cout << sum(m) - sum(n-1);
			}
		}
		cout << "\n\n";
	}

	return 0;
}