#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int x, y;
	cin >> x >> y;
	int a, b, c, d, q, r;
	a = 100 - x;
	b = 100 - y;
	c = 100 - (a + b);
	d = a * b;
	q = d / 100;
	r = d % 100;

	cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << q << ' ' << r << '\n';
	cout << c + q << ' ' << r;


	return 0;
}