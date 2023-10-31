#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;
	pair<int, int> minbound(INT_MAX, INT_MAX), maxbound(INT_MIN, INT_MIN);

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		if (n == 1)
		{
			cout << 0;
			return 0;
		}

		if (x < minbound.first)
			minbound.first = x;
		if (y < minbound.second)
			minbound.second= y;
		if (x > maxbound.first)
			maxbound.first = x;
		if (y > maxbound.second)
			maxbound.second = y;
	}

	int width = maxbound.first - minbound.first;
	int height = maxbound.second - minbound.second;

	cout << width * height;
	return 0;
}