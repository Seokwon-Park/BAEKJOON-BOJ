#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	cout << max(a + b, a - b) << '\n';
	cout << min(a + b, a - b);

	return 0;
}