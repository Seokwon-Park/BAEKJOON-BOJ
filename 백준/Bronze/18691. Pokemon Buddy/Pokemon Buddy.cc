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

	int tc;
	cin >> tc;

	vi v(4);
	v[1] = 1;
	v[2] = 3;
	v[3] = 5;

	while (tc--)
	{
		int g, c, e;
		cin >> g >> c >> e;
		cout << max(0, (e - c)) * v[g] << '\n';
	}
	return 0;
}