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

	int n;
	int casenum = 1;
	while (cin >> n)
	{
		if (n == 0) break;
		double res = 0.0;
		for (int i = 0; i < n; i++)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			res += ((0.8 - 15.5 / 85)* a);
			res += ((1.0 - 32.0 / 85) * b);
			res += ((1.2 - 40.0 / 85) * c);
			res += 0.6 * d;
		}

		cout << "Case #" << casenum++ << ": RM" << fixed << setprecision(2) <<res << '\n';
	}
	

	return 0;
}