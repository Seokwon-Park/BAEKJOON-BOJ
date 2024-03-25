#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll w1, h1, w2, h2;
	cin >> w1 >> h1 >> w2 >> h2;

	cout << max(w1, w2) * 2 + (h1 + h2) * 2 + 4;

	return 0;
}