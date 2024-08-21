#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int v[4];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		v[m]++;
	}

	int ans = 0;
	ans += min(v[0], v[3]) * 3;
	ans += min(v[1], v[2]) * 3;
	int tt, tf, ft, ff;
	if (v[0] > v[3])
	{
		ff = v[0] - v[3];
		if (v[1] > v[2]) // 01 ^ 00;
		{
			ft = v[1] - v[2];
			ans += min(ff, ft);
		}
		else
		{
			tf = v[2] - v[1];
			ans += min(ff, tf) * 2;
		}
	}
	else
	{
		tt = v[3]- v[0];
		if (v[1] > v[2]) // 01 ^ 00;
		{
			ft = v[1] - v[2];
			ans += min(tt, ft)*2;
		}
		else
		{
			tf = v[2] - v[1];
			ans += min(tt, tf);
		}
	}
	

	cout << ans;


	return 0;
}