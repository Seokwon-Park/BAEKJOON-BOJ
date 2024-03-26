#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	int d = (a + b + c) / 3;
	cout << (d - a) * 2 + (d - b);

	return 0;
}