#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

ll v[105][3];
ll res[105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> v[j][0] >> v[j][1] >> v[j][2];
		}
		ll k, d, a;
		cin >> k >> d >> a;
		ll result = 0;
		for (int j = 0; j < m; j++)
		{
			ll tmp = k * v[j][0] - d * v[j][1] + a * v[j][2];
			if (tmp >= 0)
			{
				result += tmp;
			}
		}
		cout << result << '\n';
	}
	
	
	return 0;
}