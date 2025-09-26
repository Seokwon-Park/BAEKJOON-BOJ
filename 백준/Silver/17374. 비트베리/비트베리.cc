#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int p, q, a, b, c, d;
		cin >> p >> q >> a >> b >> c >> d;
		int coin = q / c * d;

		// y = p + a * x;
		// y = coin - b* x;
		// coin-p = (a+b)x;
		// coin-p/(a+b) = x;
		int x = ceil((double)(coin - p) / (a + b));
		int	result = max(coin - b * x, p + a * (x - 1));
		
		cout << (result <0? 0 : result) << '\n';
	}

	return 0;
}