#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	double k;
	cin >> k;
	double res = k * 0.01 + 25;
	res = max(res, 100.0);
	res = min(res, 2000.0);

	cout << fixed;
	cout.precision(2);
	cout << res;

	return 0;
}