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

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += i * i * i;
	}

	cout << ans;

	return 0;
}