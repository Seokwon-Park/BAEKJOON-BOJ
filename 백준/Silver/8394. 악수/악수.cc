#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int dp1 = 0;
	int dp2 = 1;
	int dp;
	for (int i = 1; i <= n; i++)
	{
		dp = (dp1 + dp2)%10;
		dp1 = dp2 %10;
		dp2 = dp;
	}
	cout << dp;

	return 0;
}