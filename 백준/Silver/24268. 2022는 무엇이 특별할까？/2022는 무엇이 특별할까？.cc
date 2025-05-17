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

	ll n, d;
	cin >> n >> d;

	vector<int> v(d);
	for (int i = 0; i < d; i++)
	{
		v[i] = i;
	}

	ll ans = INT_MAX;
	do
	{
		if (v[0] == 0) continue;
		ll res = 0;
		for (int i = 0; i < d; i++)
		{
			int num = v[i];
			for (int j = 0; j < d-i-1; j++)
			{
				num *= d;
			}
			res += num;
		}
		if (res > n)
		{
			ans = min(ans, res);
		}
	} while (next_permutation(v.begin(), v.end()));

	if (ans == INT_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}

	return 0;
}