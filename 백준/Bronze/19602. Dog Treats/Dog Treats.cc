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

	int s, m, l;
	cin >> s >> m >> l;
	int res = s + m * 2 + l * 3;
	cout << (res >= 10 ? "happy" : "sad");

	return 0;
}