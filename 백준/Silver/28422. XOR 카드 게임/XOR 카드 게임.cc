#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dp[100005];
int v[100005];

int calc(int n)
{
	int res = 0;
	while (n)
	{
		res += n % 2;
		n /= 2;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	dp[0] = 0;
	dp[1] = -1;

	for (int i = 2; i <= n; i++)
	{
		if (i - 2 >= 0 && dp[i - 2] != -1)
			dp[i] = max(dp[i], dp[i - 2] + calc(v[i - 1] ^ v[i - 2]));
		if (i - 3 >= 0 && dp[i - 3] != -1)
			dp[i] = max(dp[i], dp[i - 3] + calc(v[i - 1] ^ v[i - 2] ^ v[i - 3]));
	}

	//1개만 남게되는 경우는 1인 경우밖에 없는듯?
	if (n == 1)
	{
		cout << 0;
	}
	else
	{
		cout << dp[n];
	}

	return 0;
}