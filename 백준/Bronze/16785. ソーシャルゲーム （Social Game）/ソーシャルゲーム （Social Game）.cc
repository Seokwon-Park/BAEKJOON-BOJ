#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	int d = 0;
	while (c > 0)
	{
		c -= a;
		d++;
		if (d % 7 ==0)
			c -= b;
	}
	cout << d;

	return 0;
}