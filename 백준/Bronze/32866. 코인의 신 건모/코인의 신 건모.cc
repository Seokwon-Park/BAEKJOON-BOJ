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

	double n, x;
	cin >> n >> x;
	double lost = n * (1.0 - (x / 100.0));
	cout << fixed << setprecision(6) << ((n - lost) / lost) * 100.0;


	return 0;
}
 