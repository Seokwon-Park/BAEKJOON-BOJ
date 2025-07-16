#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	double w, h;
	int n;
	cin >> w >> h >> n;
	double st = w / 2 - w / n;
	double res = 0.0;
	while (st > 0)
	{
		res += h * (st / (w / 2));
		st -= w / n;
	}
	cout << fixed << setprecision(6)<< res * 2;

	return 0;
}