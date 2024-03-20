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
	
	vec<char> v(5);
	char n;
	for (char& i : v)
		cin >> i;
	cout << (v[0] + v[2] - '0' == v[4] ? "YES" : "NO");

	return 0;
}