#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

const double PI = acos(-1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int app = a * 3 + b * 2 + c;
	int bnn = d * 3 + e * 2 + f;

	if (bnn == app)
		cout << 'T';
	else if (bnn > app)
		cout << 'B';
	else
		cout << 'A';


	return 0;
}