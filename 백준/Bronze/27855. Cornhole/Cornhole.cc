#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int h1, b1, h2, b2;
	cin >> h1 >> b1 >> h2 >> b2;
	int a = h1 * 3 + b1;
	int b = h2 * 3 + b2;
	if (a == b)
		cout << "NO SCORE";
	else if (a > b)
		cout << 1 << ' ' << a - b;
	else
		cout << 2 << ' ' << b - a;

	return 0;
}