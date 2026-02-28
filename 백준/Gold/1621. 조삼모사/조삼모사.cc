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

ll dp[1000005];
ll v[1000005];
ll prv[1000005];
ll isbind[1000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int k, c;
	cin >> k >> c;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	fill(dp, dp + n + 5, INF);
	dp[0] = 0;
	prv[0] = -1;

	for (int i = 1; i <= n; i++)
	{
		dp[i] = min(dp[i], dp[i - 1] + v[i]);
		prv[i] = i - 1;
		if (i >= k)
		{
			if (dp[i] > dp[i - k] + c)
			{
				dp[i] = dp[i - k] + c;
				prv[i] = i - k;
				isbind[i] = true;
			}
		}
	}

	int cur = n;
	vector<int> ktimes;
	while (prv[cur] != -1)
	{
		if (isbind[cur])
		{
			ktimes.push_back(prv[cur]);
		}
		cur = prv[cur];
	}

	reverse(ktimes.begin(), ktimes.end());

	cout << dp[n] << '\n' << ktimes.size() << '\n';
	for (int i : ktimes)
	{
		cout << i + 1 << ' ';
	}


	return 0;
}
