#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<ll> files(n);
	for (int i = 0; i < n; i++)
	{
		cin >> files[i];
	}
	ll clu;
	cin >> clu;
	ll ans = 0;
	for (ll i : files)
	{
		ans += (i / clu) * clu;
		if (i % clu != 0)
			ans += clu;
	}
	cout << ans;

	return 0;
}