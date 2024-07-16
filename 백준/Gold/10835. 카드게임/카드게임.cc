#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int l[2005];
int r[2005];
int dp[2005][2005];
int n;


int func(int ll, int rr)
{
	if (ll == n || rr == n) return 0;

	if (dp[ll][rr] != -1)return dp[ll][rr];
	dp[ll][rr] = 0;
	if (l[ll] > r[rr])
		dp[ll][rr] += func(ll, rr + 1) + r[rr];
	else
		dp[ll][rr] += max(func(ll + 1, rr), func(ll + 1, rr + 1));
	return dp[ll][rr];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> l[i];
	for (int i = 0; i < n; i++)
		cin >> r[i];

	fill_n(&dp[0][0], 2005 * 2005, -1);
	
	cout << func(0, 0);
		

	return 0;
}