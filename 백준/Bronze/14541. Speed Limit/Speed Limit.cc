#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (cin >> n)
	{
		if (n == -1)break;
		int ans = 0;
		int prev = 0;
		int a, b;
		while (n--)
		{
			cin >> a >> b;
			ans += a * (b - prev);
			prev = b;
		}
		cout << ans << " miles\n";
	}


	return 0;
}