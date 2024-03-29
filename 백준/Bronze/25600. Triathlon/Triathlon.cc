#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int mx = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		int a, d, g;
		cin >> a >> d >> g;
		int res = a * (d + g);
		if (a == d + g)
			res *= 2;
		mx = max(mx, res);
	}
	cout << mx;

	return 0;
}