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
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m, k, d;
		cin >> n >> m >> k >> d;

		int inner = m * (m - 1) / 2;
		int outer = m * (n - 1) * n * m / 2;
		
		int b = 1;
		int prev = -1;
		while (1)
		{
			int a = b * k;
			int x = inner * a * n;
			int y = outer * b;
			if (x + y <= d)
			{
				prev = x + y;
			}
			else
			{
				break;
			}
			b++;
		}
		cout << prev;
		cout << '\n';
	}

	return 0;
}