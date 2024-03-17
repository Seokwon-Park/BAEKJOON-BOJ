#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ca, ba, pa;
	int cr, br, pr;
	cin >> ca >> ba >> pa;
	cin >> cr >> br >> pr;

	cout <<
		(ca >= cr ? 0 : cr - ca) +
		(ba >= br ? 0 : br - ba) +
		(pa >= pr ? 0 : pr - pa);

	return 0;
}