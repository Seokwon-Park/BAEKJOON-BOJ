#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	
	int tc = 1;
	while (1)
	{
		int t;
		cin >> t;
		if (t < 0)break;
		vector<double> xx, yy;
		double mm = 0;
		for (int i = 0; i < t; i++)
		{
			double x, y, m;
			cin >> x >> y >> m;
			xx.push_back(x*m);
			yy.push_back(y*m);
			mm += m;
		}
		double xc = 0;
		double yc = 0;
		for (int i = 0; i < t; i++)
		{
			xc += xx[i] / mm;
			yc += yy[i] / mm;
		}
		cout << fixed;
		cout.precision(2);
		cout << "Case " << tc++ << ": " << xc << ' ' << yc << '\n';

	}

	return 0;
}