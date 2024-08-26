#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int dp[105];
int top[105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<tuple<int, int, int, int>> v(1);
	for (int i = 1; i <= n; i++)
	{
		int a, h, w;
		cin >> a >> h >> w;
		v.push_back(tie(a, w, h, i));
		dp[i] = h;
	}

	sort(v.begin(), v.end(), [](auto a, auto b)
		{
			return get<0>(a) < get<0>(b);
		});

	for (int i = 1; i <= n; i++)
	{
		int a, w, h, ix;
		tie(a, w, h, ix) = v[i];
		for (int j = i + 1; j <= n; j++)
		{
			int aa, ww, hh, ixx;
			tie(aa, ww, hh, ixx) = v[j];
			if (w < ww)
			{
				if (dp[ixx] < hh + dp[ix])
				{
					dp[ixx] = hh + dp[ix];
					top[ixx] = ix;
				}
			}
		}
	}

	int ix = max_element(dp + 1, dp + n + 1) - dp;
	vector<int> ans;
	while (ix != 0)
	{
		ans.push_back(ix);
		ix = top[ix];
	}

	reverse(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i << '\n';



	return 0;
}
