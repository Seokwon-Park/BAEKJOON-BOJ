#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	double res = 0;
	while (n--)
	{
		double m;
		cin >> m;
		res += m * m * m;
	}

	cout << fixed;
	cout.precision(6);
	cout << pow(res, 1.0 / 3.0);

	return 0;
}