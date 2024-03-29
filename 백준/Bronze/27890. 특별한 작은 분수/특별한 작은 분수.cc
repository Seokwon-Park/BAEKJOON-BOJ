#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, n;
	cin >> x >> n;
	int t = 0;
	while (t < n)
	{
		if (x % 2 == 0)
			x = (x / 2) ^ 6;
		else
			x = (2 * x) ^ 6;
		t++;
	}
	cout << x;

	return 0;
}