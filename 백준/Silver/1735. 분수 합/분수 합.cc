#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int bj = a * d + c * b;
	int bm = b * d;

	int g = gcd(bj, bm);

	std::cout << bj/ g<< ' ' << bm/g;

	return 0;
}