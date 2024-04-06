#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

ull dp[116];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	double xa, ya, xb, yb, xc, yc;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;

	if ((xa == xb && xb == xc) || (ya == yb && yb == yc))
	{
		cout << -1.0;
		return 0;
	}

	if ((ya - yb) / (xa - xb) == (yb - yc) / (xb - xc))
	{
		cout << -1.0;
		return 0;
	}

	double abx = abs(xa-xb);
	double bcx = abs(xb-xc);
	double cax = abs(xc-xa);
	double aby = abs(ya - yb);
	double bcy = abs(yb - yc);
	double cay = abs(yc - ya);

	double res1 = sqrt(abx * abx + aby * aby) + sqrt(bcx * bcx + bcy * bcy);
	double res2 = sqrt(bcx * bcx + bcy * bcy) + sqrt(cax * cax + cay * cay);
	double res3 = sqrt(cax * cax + cay * cay) + sqrt(abx * abx + aby * aby);

	double mx = max({ res1,res2,res3 }) * 2.0;
	double mn = min({ res1,res2,res3 }) * 2.0;
	cout << fixed;
	cout.precision(9);
	cout << mx - mn;
	return 0;
}
