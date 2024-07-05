#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;

	if (n == 1)
		cout << 0;
	else if ((x == 1 || x == n) && (y == 1 || y == n))
		cout << 2;
	else if ((x == 1 || x == n) || (y == 1 || y == n))
		cout << 3;
	else
		cout << 4;

	return 0;
}