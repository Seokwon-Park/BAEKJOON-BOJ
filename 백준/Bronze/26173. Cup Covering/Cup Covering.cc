#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	double a;
	cin >> a;

	const double PI = acos(-1);
	// PI r^2 = a;
	// r = sqrt(a/PI)
	double r = sqrt(a / PI);
	cout << fixed;
	cout.precision(9);
	cout << 2 * r;

	return 0;
}