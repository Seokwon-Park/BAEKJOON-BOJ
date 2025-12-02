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

int dp1[1005];
int dp2[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<tiii> v(n);
	for (int i = 0; i < n; i++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		v[i] = tie(x, y, c);
		
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		int x, y, c;
		tie(x, y, c) = v[i];
		dp1[i] = c;
		dp2[i] = c;
	}

	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int ix, iy, ic, jx, jy, jc;
			tie(ix, iy, ic) = v[i];
			tie(jx, jy, jc) = v[j];
			if (jy < iy)
			{
				dp1[i] = max(dp1[i], dp1[j] + ic);
			}
			if (jy > iy)
			{
				dp2[i] = max(dp2[i], dp2[j] + ic);
			}
		}
		
	}

	for (int i = 0; i < n; i++)
	{
		ans = max({ ans, dp1[i], dp2[i] });
	}
	cout << ans;

	return 0;
}