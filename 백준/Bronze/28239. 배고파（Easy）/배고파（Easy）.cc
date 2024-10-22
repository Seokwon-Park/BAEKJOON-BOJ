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

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		ll m;
		cin >> m;
		vector<int> xy;
		ll cur = 0;
		while ((1LL << cur) <= m)
		{
			if ((m & (1LL <<cur)) != 0)
			{
				xy.push_back(cur);
			}
			cur++;
		}
		if (xy.size() == 1)
		{
			cout << xy[0]-1 << ' ' << xy[0]-1 << '\n';
		}
		else
		{
			cout << xy[0] << ' ' << xy[1] << '\n';
		}
	}
	

	return 0;
}