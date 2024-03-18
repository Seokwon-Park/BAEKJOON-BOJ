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

	int res = INT_MIN;
	int cur = 0;
	for (int i = 0; i < 10; i++)
	{
		int a, b;
		cin >> a >> b;
		cur -= a;
		cur += b;
		res = max(res, cur);
	}
	cout << res;

	return 0;
}