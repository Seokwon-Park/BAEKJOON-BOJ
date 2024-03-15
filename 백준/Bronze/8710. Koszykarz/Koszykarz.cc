#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int k, w, m;
	cin >> k >> w >> m;
	int need = w - k;
	cout << need / m + (need % m == 0 ? 0 : 1);

	return 0;
}
