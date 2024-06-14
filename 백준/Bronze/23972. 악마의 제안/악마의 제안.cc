#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll k, n;
	cin >> k >> n;
	// x >= n*k /(n-1);
	if (n == 1)
	{
		cout << -1;
		return 0;
	}
	ll res = n * k / (n - 1LL);
	if (n * k % (n - 1LL))
		res++;
	cout << res;
	

	return 0;
}
