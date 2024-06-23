#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<ll> v(6);
		ll total = 0;
		for (int i = 0; i < 6; i++)
		{
			cin >> v[i];
			total += v[i];
		}
		int ans = 1;
		while (total <= n)
		{
			total = 0;
			vector<ll> nv(6);
			for (int i = 0; i < 6; i++)
			{
				nv[i] = v[i] + v[(i + 1) % 6] + v[(i + 5) % 6] + v[(i + 3) % 6];
				total += nv[i];
			}
			v = nv;
			ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}