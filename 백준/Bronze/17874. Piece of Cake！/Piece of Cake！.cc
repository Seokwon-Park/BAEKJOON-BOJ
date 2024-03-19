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

	int n, h, v;
	cin >> n >> h >> v;
	int a, b, c, d;
	a = h * v;
	b = h * (n - v);
	c = (n - h) * v;
	d = (n - h) * (n - v);

	cout << max({ a,b,c,d }) * 4;

	return 0;
}
