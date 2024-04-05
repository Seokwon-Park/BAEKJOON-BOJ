#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll ans = 0;
	vector<int> v(n);
	for (int& i : v)
		cin >> i;
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < n; i++)
	{
		ans += max(0,(v[i] - i));
	}
	cout << ans;
	
	return 0;
}