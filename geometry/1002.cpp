#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	int x1, y1, r1, x2, y2, r2;
	double dist;
	
	for (int i = 0; i < t; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2 && r1 == r2)
		{
			cout << -1 << '\n';
			continue;
		}
		dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		if(dist == 0)cout << 0 << '\n';
		else if (abs(r1 - r2) < dist && dist < abs(r1 + r2))
			cout << 2 << '\n';
		else if (dist == abs(r1 + r2) || dist == abs(r1 - r2))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';

	}


	
	
	return 0;
}

