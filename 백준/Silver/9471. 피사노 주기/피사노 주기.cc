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
	for (int i = 0; i < n; i++)
	{
		int tc;
		cin >> tc;
		int m;
		cin >> m;

		vector<int> dp(2, 1);
		int prev = 1;
		int cur = 1;
		int period = 2;
		do
		{
			prev = cur;
			dp.push_back((dp[period - 1] + dp[period - 2])%m);
			cur = dp[period];
			period++;
		} while (prev != 1 || cur != 1);

		cout << tc <<' '<<  period - 2 << '\n';
	}

	return 0;
}