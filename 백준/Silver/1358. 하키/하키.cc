#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int w, h, x, y, p;

bool isInside(int px, int py)
{
	double r = h / 2.0;
	if (px >= x && py >= y && px <= x + w && py <= y + h)
		return true;
	double a1 = x;
	double b1 = y + r;
	double res1 = (px - a1) * (px - a1) + (py - b1) * (py - b1);
	if (res1 <= r * r)
		return true;

	double a2 = x + w;
	double b2 = y + r;
	double res2 = (px - a2) * (px - a2) + (py - b2) * (py - b2);
	if (res2 <= r * r)
		return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> w >> h >> x >> y >> p;
	int cnt = 0;
	while (p--)
	{
		int px, py;
		cin >> px >> py;
		if (isInside(px, py))
			cnt++;
	}

	cout << cnt;

	return 0;
}
