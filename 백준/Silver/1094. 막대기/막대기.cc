#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int ans = 0;
	while (n)
	{
		ans += n & 1;
		n >>= 1;
	}
	cout << ans;
	
	return 0;
}