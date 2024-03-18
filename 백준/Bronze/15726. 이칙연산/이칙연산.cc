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
	
	double a, b, c;
	cin >> a >> b >> c;
	cout << (int)max(a * b / c, a / b * c);


	return 0;
}