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

	int c;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		int n;
		cin >> n;
		int ans = 1;
		int tmp = n;
		for (int i = 2; i <= n; i++)
		{
			int res = 0;
			while (tmp % i == 0)
			{
				tmp /= i;
				res++;
			}
			if (res != 0)
			{
				ans *= res + 1;
			}
			if (tmp == 1) break;
		}
		cout << n << ' ' << ans << '\n';
	}


	return 0;
}