#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, d, p;
	cin >> a >> b >> c >> d >> p;
	int ares = a * p;
	int bres = b + max(0, p-c) * d;
	cout << min(ares, bres);

	return 0;
}