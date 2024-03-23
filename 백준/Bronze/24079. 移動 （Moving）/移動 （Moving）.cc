#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y, z;
	cin >> x >> y >> z;
	int a= (x + y) * 60;
	int b = z * 60 + 30;
	if (a <= b)
		cout << 1;
	else
		cout << 0;

	return 0;
}