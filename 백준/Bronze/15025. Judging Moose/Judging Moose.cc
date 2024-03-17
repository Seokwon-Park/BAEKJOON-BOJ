#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int l, r;
	cin >> l >> r;
	if (l + r == 0)
	{
		cout << "Not a moose";
	}
	else if (l == r)
	{
		cout << "Even " <<  l * 2;
	}
	else
	{
		cout << "Odd " << max(l, r) * 2;
	}

	return 0;
}