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

	double n;
	cin >> n;
	double sq = sqrt(n);

	cout << fixed;
	cout.precision(6);
	cout << sq * 4;

	return 0;
}
