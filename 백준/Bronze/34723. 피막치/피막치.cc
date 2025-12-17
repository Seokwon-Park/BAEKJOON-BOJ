#include <bits/stdc++.h>

using namespace std;

using ll = long long;
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

	int p, m, c, x;
	cin >> p >> m >> c >> x;
	
	int ans = INF;
	for(int i = 1 ; i<= p; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 1; k <= c; k++)
				ans = min(ans, abs((i + j) * (j + k) - x));

	cout << ans;
	
	return 0;
}