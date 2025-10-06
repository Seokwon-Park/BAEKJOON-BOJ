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

	int n, w;
	cin >> n >> w;

	int res = n * 10;
	res += (n >= 3 ? 20 : 0);
	res += (n == 5 ? 50 : 0);
	res += (w > 1000 ? -15 : 0);
	res = max(res, 0);

	cout << res;

	return 0;
}