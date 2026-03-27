#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

bool dp[10005][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;

	int s, e;
	cin >> s >> e;

	string aa, bb;

	for (int i = 0; i < n; i++)
	{
		if (i == s || i == e)
		{
			continue;
		}
		aa += a[i];
	}

	dp[0][0] = 1;
	dp[0][1] = a[s] == b[0];
	for (int i = 1; i < n; i++)
	{
		if (dp[i - 1][0])
		{
			if (i < aa.size()) dp[i][0] |= aa[i] == b[i];
			dp[i][1] |= a[s] == b[i];
		}
		if (dp[i - 1][1])
		{
			if (i - 1 < aa.size()) dp[i][1] |= aa[i - 1] == b[i];
			dp[i][2] |= a[e] == b[i];
		}
		if (dp[i - 1][2])
		{
			if (i - 2 < aa.size()) dp[i][2] |= aa[i - 2] == b[i];
		}
	}

	cout << (dp[n - 1][2] ? "YES" : "NO");

	return 0;
}