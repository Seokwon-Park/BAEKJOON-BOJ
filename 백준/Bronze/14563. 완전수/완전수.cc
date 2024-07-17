#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		int res = (m == 1)? 0 : 1;
		for (int j = 2; j * j <= m; j++)
		{
			if (m % j == 0)
			{
				if (m / j == j)
					res += j;
				else
				{
					res += m / j;
					res += j;
				}
			}
		}
		if (res == m)
			cout << "Perfect";
		else if (res < m)
			cout << "Deficient";
		else
			cout << "Abundant";
		cout << '\n';
	}

	return 0;
}
