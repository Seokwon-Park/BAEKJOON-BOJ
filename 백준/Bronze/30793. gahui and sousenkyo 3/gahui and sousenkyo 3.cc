#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	double p, r;
	cin >> p >> r;
	double res = p / r;
	if (res < 0.2)
		cout << "weak";
	else if (res < 0.4)
		cout << "normal";
	else if (res < 0.6)
		cout << "strong";
	else
		cout << "very strong";

	return 0;
}