
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

	double x, y;
	cin >> x >> y;
	int n;
	cin >> n;
	vd v(n + 1);
	v[0] = x / y;
	for (int i = 1; i <= n; i++)
	{
		double xx, yy;
		cin >> xx >> yy;
		v[i] = xx / yy;
	}
	sort(v.begin(), v.end());
	
	cout << fixed;
	cout.precision(2);
	cout << v[0] * 1000;

	return 0;
}