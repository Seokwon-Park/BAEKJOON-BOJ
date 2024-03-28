#include <bits/stdc++.h>


using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	if (n == 1 || m == 1)
		cout << n * m;
	else
		cout << ((n + m) * 2 - 4);

	return 0;
}