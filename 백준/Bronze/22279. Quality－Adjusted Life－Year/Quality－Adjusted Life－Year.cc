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
	
	int n;
	cin >> n;
	double ans = 0.0;
	for (int i = 0; i < n; i++)
	{
		double a, b;
		cin >> a >> b;
		ans += a * b;
	}
	cout << fixed << setprecision(3) << ans;

	return 0;
}


