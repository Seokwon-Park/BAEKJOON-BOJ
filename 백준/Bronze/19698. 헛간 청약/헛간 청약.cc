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
	
	int n, w, h, l;
	cin >> n >> w >> h >> l;
	cout << min(n, (w / l) * (h / l));

	return 0;
}