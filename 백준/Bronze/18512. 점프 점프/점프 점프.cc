#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y, p1, p2;
	cin >> x >> y >> p1 >> p2;

	int a = p1;
	int b = p2;
	while (a != b)
	{
		if (a < b)
		{
			a += x;
		}
		else if (a > b)
		{
			b += y;
		}
		if (a > 10000 || b > 10000)
		{
			cout << -1;
			return 0;
		}
	}
	cout << a;

	return 0;
}