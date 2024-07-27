#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int v[1005];
int dp[1005][1005];

int func(int l, int r, bool isMyTurn)
{
	if (l > r) return 0;
	if (dp[l][r] != -1) return dp[l][r];

	if (isMyTurn)
		return dp[l][r] = max(v[l] + func(l + 1, r, !isMyTurn), func(l, r - 1, !isMyTurn) + v[r]);
	else
		return dp[l][r] = min(func(l + 1, r, !isMyTurn), func(l, r - 1, !isMyTurn));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			fill(dp[i], dp[i] + n, -1);
			cin >> v[i];
		}
		cout << func(0, n - 1, true) << '\n';
		
	}
	
	return 0;
}