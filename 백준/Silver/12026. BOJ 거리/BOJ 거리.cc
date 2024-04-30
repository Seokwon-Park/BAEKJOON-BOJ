#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

ll dp[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;

	string p = "BOJ";
	map<char, int> m;
	m['B'] = 0;
	m['O'] = 1;
	m['J'] = 2;

	fill(dp, dp + 1005, 0x3f3f3f);
	dp[0] = 0;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int curc = m[s[i]];
			if (s[j] == p[(curc + 2) % 3])
			{
				dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
			}
		}
	}

	if (dp[n - 1] == 0x3f3f3f)
		cout << -1;
	else
		cout << dp[n - 1];

	return 0;
}
