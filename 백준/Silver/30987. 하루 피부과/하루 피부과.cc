#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int a, b, c, d, e;
int expr(int x)
{
	return a / 3 * x * x * x + (b - d) / 2 * x * x + (c - e) * x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x1, x2;
	cin >> x1 >> x2;
	cin >> a >> b >> c >> d >> e;
	
	cout << expr(x2) - expr(x1);
	



	return 0;
}