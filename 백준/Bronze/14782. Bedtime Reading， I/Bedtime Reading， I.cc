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
	
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			if (n / i == i)
			{
				ans += i;
			}
			else
			{
				ans += n / i;
				ans += i;
			}
		}
	}
	cout << ans;

	return 0;
}