#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--)
	{
		unordered_map<ll, int> m;
		int t;
		cin >> t;
		ll ans = 0;
		for (int i = 0; i < t; i++)
		{
			ll tmp;
			cin >> tmp;
			m[tmp]++;
			if (ans == 0 && m[tmp] > t / 2)
			{
				ans = tmp;
			}

		}
		if (ans != 0)
		{
			cout << ans;
		}
		else
		{
			cout << "SYJKGW";
		}

		cout << '\n';
	}

	return 0;
}