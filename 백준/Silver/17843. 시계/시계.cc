#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		double h, m, s;
		cin >> h >> m >> s;
		vector<double> v;
		v.push_back(s * 6.0);
		double mangle = m * 6.0 + 6 * (s / 60.0);
		v.push_back(mangle);
		double hangle = h * 30.0 + 30.0 * (m / 60.0) + 30.0 * (s / 3600.0);
		v.push_back(hangle);
		sort(v.begin(), v.end());
		double ans = 360.0;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[(i + 1) % 3] < v[i])
			{
				ans = min(ans, abs((v[(i+1)%3] + 360.0-v[i])));
			}
			else
			{
				ans = min(ans, v[(i + 1) % 3] - v[i]);
			}
		}
		cout << fixed << setprecision(6) << ans << '\n';


	}

	return 0;
}