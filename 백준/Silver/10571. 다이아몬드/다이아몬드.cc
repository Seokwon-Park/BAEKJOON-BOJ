#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

ll dp[205];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		fill(dp, dp + n + 5, 1);
		vector<pair<double,double>> v(n);
		for (int i = 0; i < n; i++)
		{
			double w, c;
			cin >> w >> c;
			v[i] = { w,c };
		}

		for (int i = 1; i < n; i++)
		{
			auto [w, c] = v[i];
			for (int j = 0; j < i; j++)
			{
				auto [ww, cc] = v[j];
				if (w > ww && c < cc)
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		cout << *max_element(dp, dp + n) << '\n';
	}

	return 0;
}



