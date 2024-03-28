#include <bits/stdc++.h>


using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int p, c;
	cin >> p >> c;
	cout << p * 50 - c * 10 + (p > c ? 500 : 0);


	return 0;
}