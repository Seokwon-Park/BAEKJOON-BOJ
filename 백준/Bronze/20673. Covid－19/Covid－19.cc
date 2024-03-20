#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int p, q;
	cin >> p >> q;

	if (p <= 50 && q <= 10)
		cout << "White";
	else if (q > 30)
		cout << "Red";
	else
		cout << "Yellow";


	return 0;
}