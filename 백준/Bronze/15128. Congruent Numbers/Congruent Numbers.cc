#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll p1, q1, p2, q2;
	cin >> p1 >> q1 >> p2 >> q2;
	if ((p1 * p2) % (q1 * q2) != 0)
	{
		cout << 0;
	}
	else
	{
		if (((p1 * p2) / (q1 * q2)) % 2 != 0)
			cout << 0;
		else
			cout << 1;
	}


	return 0;
}