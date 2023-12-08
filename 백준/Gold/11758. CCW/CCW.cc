#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;

	int px1, py1, px2, py2;
	px1 = x1 - x2;
	py1 = y1 - y2;

	cin >> x3 >> y3;

	px2 = x3 - x2;
	py2 = y3 - y2;

	int ccw = px1 * py2 - py1 * px2;

	if (ccw < 0)
		cout << 1;
	else if (ccw == 0)
		cout << 0;
	else
		cout << -1;
	

	return 0;
}