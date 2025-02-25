
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

	int p, q;
	cin >> p >> q;

	set<int> pv, qv;
	for (int i = 1; i <= p; i++)
	{
		if (p % i == 0)
		{
			pv.insert(i);
			pv.insert(p / i);
		}
	}

	for (int i = 1; i <= q; i++)
	{
		if (q % i == 0)
		{
			qv.insert(i);
			qv.insert(q / i);
		}
	}

	for (auto i : pv)
	{
		for (int j : qv)
		{
			cout << i << ' ' << j << '\n';
		}
	}
	
	return 0;
}
