#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	int mx = max({ a,b,c });
	cout << mx * 3 - a - b - c;

	return 0;
}