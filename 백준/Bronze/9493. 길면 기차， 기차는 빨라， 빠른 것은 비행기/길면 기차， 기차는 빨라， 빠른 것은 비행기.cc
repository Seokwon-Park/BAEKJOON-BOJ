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
	
	while (1)
	{
		int m, a, b;
		cin >> m >> a >> b;
		if (m == 0 && a == 0 && b == 0)
		{
			break;
		}
		double as = m * 3600.0 / a;
		double bs = m * 3600.0 / b;
		int res = round(abs(as - bs));
		int h = res / 3600;
		int mn = res % 3600 / 60;
		int s = res % 3600 % 60;

		cout << h << ':' << setw(2) << setfill('0') << mn << ':' << setw(2)
			<< setfill('0') << s << '\n';
	}

	return 0;
}



