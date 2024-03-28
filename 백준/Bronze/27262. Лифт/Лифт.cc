#include <bits/stdc++.h>


using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, a, b;
	cin >> n >> k >> a >> b;
	int stair = (n - 1) * a;
	int elev = (k - 1) * b + (n - 1) * b;
	cout << elev << ' ' << stair;

	return 0;
}