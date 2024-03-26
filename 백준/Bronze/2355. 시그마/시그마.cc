#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;
	if (a > b)
		swap(a, b);
	cout << (b - a + 1) * (a + b) / 2;

	return 0;
}