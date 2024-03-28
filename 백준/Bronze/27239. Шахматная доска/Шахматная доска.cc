#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	char x = (n - 1) % 8 + 'a';
	int y = (n-1) / 8 + 1;
	cout << x << y;

	return 0;
}