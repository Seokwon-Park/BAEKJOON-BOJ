#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);					
	cin.tie(0);

	int n;
	cin >> n;
	
	int ans = 0;
	for (int i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			if (i * i == n)
				ans += i;
			else
				ans += i + n / i;
		}
	}
	cout << ans*5-24;

	return 0;
}
