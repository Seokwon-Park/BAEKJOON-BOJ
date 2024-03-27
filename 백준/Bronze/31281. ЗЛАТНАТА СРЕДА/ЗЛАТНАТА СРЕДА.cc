#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, c;
	cin >> a >> b >> c;
	if ((a < b && a > c) || (a <c && a>b))
		cout << a;
	else if ((b < a && b > c) || (b <c && b>a))
		cout << b;
	else
		cout << c;
	return 0;
}