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

pii v[20];


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
		int x, y;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			v[i] = { x,y };
		}

		vector<int> c(n, 0);
		for (int i = n / 2; i < n; i++)
		{
			c[i] = 1;
		}

		double ans = DBL_MAX;
		do
		{
			double xx = 0.0;
			double yy = 0.0;
			for (int i = 0; i < n; i++)
			{
				auto [x, y] = v[i];
				
				if (c[i] == 0)
				{
					xx += x;
					yy += y;
				}
				else
				{
					xx -= x;
					yy -= y;
				}
			}
			ans = min(ans, sqrt(xx*xx + yy *yy));
		} while (next_permutation(c.begin(), c.end()));
		cout << fixed << setprecision(6) << ans << '\n';
	}

	return 0;
}
