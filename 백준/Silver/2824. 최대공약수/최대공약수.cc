#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const ll mod = 1e9;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int m;
	cin >> m;
	ll ans = 1;
	bool isLL = false;
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < n; j++)
		{
			int g = gcd(k, v[j]);
			k /= g;
			v[j] /= g;
			ans *= g;
			if (ans >= mod)
			{
				isLL = true;
				ans %= mod;
			}
		}
	}
	if (isLL)
		cout << setw(9) << setfill('0') << ans;
	else
		cout << ans;

	return 0;
}