#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int b;
	cin >> b;
	int kpa = b * 5 - 400;
	cout << kpa << '\n';
	if (kpa == 100)
		cout << 0;
	else if (kpa < 100)
		cout << 1;
	else
		cout << -1;

	return 0;
}