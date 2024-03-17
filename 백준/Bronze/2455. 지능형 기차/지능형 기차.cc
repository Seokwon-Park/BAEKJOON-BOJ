#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int mx = INT_MIN;
	int cur = 0;
	for (int i = 0; i < 4; i++)
	{
		int a, b;
		cin >> a >> b;
		cur -= a;
		cur += b;
		mx = max(mx, cur);
	}
	cout << mx;

	return 0;
}