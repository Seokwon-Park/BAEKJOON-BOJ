#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int a[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--)
	{
		double a, b;
		cin >> a >> b;
		double res = a * 2.0 / b;
		cout << fixed << setprecision(2);
		cout << "The height of the triangle is " << res << " units\n";
	}

	return 0;
}