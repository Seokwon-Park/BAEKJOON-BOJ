#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	
	int c = b / a;

	int ans = INT_MAX;
	int ans1 = 0;
	int ans2 = 0;
	for (int i = 1; i * i <= c; i++)
	{ 
		if (c % i == 0)
		{
			int d1 = i;
			int d2 = c / i;
			if (gcd(d1, d2) != 1) continue;
			if (ans > d1 + d2)
			{
				ans = min(ans, d1 + d2);
				ans1 = d1;
				ans2 = d2;
			}
		}
	}

	cout << ans1 * a << ' ' << ans2 * a;



	return 0;
}