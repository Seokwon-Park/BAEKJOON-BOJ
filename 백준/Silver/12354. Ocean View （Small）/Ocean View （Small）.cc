
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int dp[10000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for(int tc = 1; tc <=t; tc++)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		vector<int> dp(n, 1);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (v[i] < v[j])
				{
					dp[j] = max(dp[j], dp[i] + 1);
				}
			}
		}
		cout << "Case #" << tc << ": " << n - dp[n - 1] << '\n';
	}


	return 0;
}