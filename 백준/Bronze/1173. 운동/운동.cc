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

	int n, m, M, t, r;
	cin >> n >> m >> M >> t >> r;
	int cur = m;
	int tt = 0;
	int pt = 0;
	if (m + t > M)
	{
		cout << -1;
		return 0;
	}
	while (pt < n)
	{
		if (cur + t <= M)
		{
			cur += t;
			pt++;
		}
		else
		{
			cur -= r;
			cur = max(m, cur);
		}
		tt++;
	}
	cout << tt;

	return 0;
}
