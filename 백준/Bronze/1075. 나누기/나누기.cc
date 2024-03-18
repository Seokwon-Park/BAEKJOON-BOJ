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

	int n, f;
	cin >> n >> f;
	n /= 100;
	n *= 100;
	int tmp = n;
	while (tmp % f)
	{
		tmp++;
	}
	int res = tmp - n;
	string ans = to_string(res);
	if (ans.size() < 2)
	{
		ans = '0' + ans;
	}
	cout << ans;

	return 0;
}