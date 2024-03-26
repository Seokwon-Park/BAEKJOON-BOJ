#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	double a;
	cin >> a;
	double b = 100 / a;
	double c = 100 / (100 - a);

	cout << fixed;
	cout.precision(3);
	cout << b << '\n' << c;


	return 0;
}