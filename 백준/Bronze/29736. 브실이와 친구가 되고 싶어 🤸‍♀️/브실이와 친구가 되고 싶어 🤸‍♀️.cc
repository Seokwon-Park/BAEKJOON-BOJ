#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	int k, x;
	cin >> k >> x;

	int lb = max(k - x, a);
	int ub = min(k + x, b);

	int ans = max(0, ub - lb + 1);
	if (ans == 0)
		cout << "IMPOSSIBLE";
	else
		cout << ans;


	return 0;
}