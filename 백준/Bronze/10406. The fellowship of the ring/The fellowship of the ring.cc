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

	int w, n, p;
	cin >> w >> n >> p;
	int ans = 0;
	for (int i = 0; i < p; i++)
	{
		int x;
		cin >> x;
		ans += (x >= w && x <= n);
	}
	cout << ans;

	return 0;
}