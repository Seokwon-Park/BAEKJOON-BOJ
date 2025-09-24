#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int n, m;
int v[25];
int dp[25][25];

int func(int idx, int group)
{
	if (group == m)
		return 0;

	if (idx >= n)
		return -INF;

	if (dp[idx][group] != -1)
		return dp[idx][group];

	int result = func(idx + 1, group);

	int partialsum = 0;
	for (int i = idx; i < n; i++)
	{
		partialsum += v[i];
		result = max(result, partialsum + func(i + 1, group + 1));
	}

	return dp[idx][group] = result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		fill(dp[i], dp[i] + m, -1);
	}

	cout << func(0, 0);

	return 0;
}