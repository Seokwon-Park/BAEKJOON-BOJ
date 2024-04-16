#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

ll gcd(ll a, ll b)
{
	while (b)
	{
		ll tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, s;
	cin >> n >> s;
	int ans = -1;
	for (int i = 0; i < n; i++)
	{
		if (ans == -1)
		{
			cin >> ans;
			ans = abs(ans - s);
		}
		else
		{
			int m;
			cin >> m;
			m = abs(m - s);
			ans = gcd(m, ans);
		}
	}
	cout << ans;


	return 0;
}