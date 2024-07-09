#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int b[4] = { 1,0,0,2 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int ix;
		cin >> ix;

		double d, a, b, f;
		cin >> d >> a >> b >> f;
		double t = d / (a + b);
		cout << ix << ' ' << fixed << setprecision(2) << t * f << '\n';
	}
	return 0;
}