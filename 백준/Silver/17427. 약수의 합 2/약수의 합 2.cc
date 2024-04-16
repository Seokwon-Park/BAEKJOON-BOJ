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

	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += n / i * i;
	}
	cout << ans;

	return 0;
}