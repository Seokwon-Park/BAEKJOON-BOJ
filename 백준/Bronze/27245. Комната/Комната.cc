#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int w, l, h;
	cin >> w >> l >> h;
	if (min(w, l)/h >= 2 && max(w, l) / min(w, l) <= 2)
		cout << "good";
	else
		cout << "bad";

	return 0;
}