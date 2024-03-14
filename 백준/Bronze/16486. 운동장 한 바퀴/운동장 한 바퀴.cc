#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	double d1, d2;
	cin >> d1 >> d2;
	const double PI = 3.141592;

	cout << fixed;
	cout.precision(6);
	cout << d1 * 2 + 2 * PI * d2;

	return 0;
}
