#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

string s;
string toEat = "BLD";

int dp[1505][1505];

int dfs(int l, int r, int ix)
{
	if (l > r)return 0;
	if(dp[l][r] != -1) return dp[l][r];
	int lres = 0, rres = 0;
	if (s[l] == toEat[ix])
	{
		lres = dfs(l + 1, r, (ix + 1) % 3) + 1;
	}
	if (s[r] == toEat[ix])
	{
		rres = dfs(l, r - 1, (ix + 1) % 3) + 1;
	}
	return dp[l][r] = max(lres, rres);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	cin >> s;

	for(int i = 0; i< 1505; i++)
		fill(dp[i], dp[i] + 1505, -1);

	cout << dfs(0, 3 * n - 1, 0);

	return 0;
}