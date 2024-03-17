#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	int aa = b * (n % a == 0 ? n / a : n / a + 1);
	int cc = d * (n % c == 0 ? n / c : n / c + 1);
	cout << min(aa, cc);

	return 0;
}