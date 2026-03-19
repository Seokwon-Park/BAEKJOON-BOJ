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

pii v[10];
bool dp[100005];
int cnt[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cash, n;
	while (cin >> cash >> n)
	{
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			v[i] = { a,b };
		}
		fill(dp, dp + cash + 1, 0);
		dp[0] = 1;
		for (int j = 0; j < n; j++)
		{
			auto [a, b] = v[j];

			fill(cnt, cnt + cash + 1, 0);
			for (int i = 0; i <= cash - b; i++)
			{
				if (dp[i] && !dp[i+b] && cnt[i] < a)
				{
					dp[i + b] = 1;
					cnt[i + b] = cnt[i] + 1;
				}
			}
		}

		for (int i = cash; i >= 0; i--)
		{
			if (dp[i])
			{
				cout << i;
				break;
			}
		}
		cout << '\n';

	}


	return 0;
}