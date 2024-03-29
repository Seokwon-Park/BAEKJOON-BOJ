#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	vector<ll> v(5, 0);
	for (int i = 0; i < tc; i++)
	{
		cin >> v[i];
	}

	ll ans = 0;
	ll tmp = abs(v[0] - v[2]);
	if (v[0] > v[2])
		ans += tmp * 508;
	else
		ans += tmp * 108;
	tmp = abs(v[1] - v[3]);
	if (v[1] > v[3])
		ans += tmp * 212;
	else
		ans += tmp * 305;
	ans += v[4] * 707;
	cout << ans * 4763LL;

		return 0;
}