#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	bool canBuy = false;
	int mn = INT_MAX;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		if (a <= b)
		{
			canBuy = true;
			mn = min(mn, b);
		}
	}
	if (canBuy)
		cout << mn;
	else
		cout << -1;

	return 0;
}