#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int m, n;
		cin >> m >> n;
		int cnt = 0;
		cout << 1 << '\n';
		cout << "(" << 0 << "," << 0 << ")\n";
		if (n % 2 == 0)
		{
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n-1; j++)
				{
					if (i % 2 == 0)
					{
						cout << "(" << i << "," << 1+j << ")\n";
					}
					else
					{
						cout << "(" << i << "," << n - 1 -j << ")\n";
					}
				}
			}
			for (int i = m - 1; i > 0; i--)
			{
				cout << "(" << i << "," <<0<< ")\n";

			}
		}
		else
		{
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n - 1; j++)
				{
					if (i % 2 == 0)
					{
						cout << "(" << i << "," << 1 + j << ")\n";
					}
					else
					{
						cout << "(" << i << "," << n - 1 - j << ")\n";
					}
				}
			}
			for (int i = m - 1; i > 0; i--)
			{
				cout << "(" << i << "," << 0 << ")\n";

			}
		}
	}


	return 0;
}
