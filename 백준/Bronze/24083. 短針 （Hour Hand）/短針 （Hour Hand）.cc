#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	cout << ((a + b) % 12 == 0 ? 12 : (a + b) % 12);

	return 0;
}