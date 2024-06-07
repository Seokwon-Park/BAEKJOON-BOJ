#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int xymin = min(x, y);
	int half = c * xymin * 2 + a*(x-xymin) + b*(y-xymin);
	int halfonly = c * max(x, y) * 2;
	int one = a * x + b * y;

	cout << min({ half, halfonly, one });

	return 0;
}