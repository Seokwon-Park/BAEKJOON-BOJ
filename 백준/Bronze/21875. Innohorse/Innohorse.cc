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

	string a, b;
	cin >> a >> b;
	int x = abs(a[0] - b[0]);
	int y = abs(a[1] - b[1]);
	if (x > y) swap(x, y);
	cout << x << ' ' << y;

	return 0;
}