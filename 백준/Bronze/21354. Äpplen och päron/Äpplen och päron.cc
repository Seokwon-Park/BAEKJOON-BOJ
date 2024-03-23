#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a, p;
	cin >> a >> p;
	a *= 7;
	p *= 13;

	if (a == p)
		cout << "lika";
	else if (a < p)
		cout << "Petra";
	else
		cout << "Axel";
	return 0;
}