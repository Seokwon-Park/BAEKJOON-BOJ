#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int a[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l, t;
	cin >> l >> t;
	int loser = l - t;
	cout << t - loser;

	return 0;
}