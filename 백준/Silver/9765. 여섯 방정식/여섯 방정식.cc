#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

ll c[7];
ll x[8];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1; i <= 6; i++)
		cin >> c[i];

	x[2] = gcd(c[1], c[5]);
	x[1] = c[1] / x[2];
	x[3] = c[5] / x[2];

	x[6] = gcd(c[3], c[6]);
	x[5] = c[6] / x[6];
	x[7] = c[3] / x[6];
	


	cout << x[1] << ' ' << x[2] << ' ' << x[3] << ' ' << x[5] << ' ' << x[6] << ' ' << x[7];
	return 0;

}