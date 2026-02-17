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

	double n;
	while (cin >> n)
	{
		if (n == 0.0) break;
		double cur = 0.0;
		double div = 2.0f;
		int ans = 0;
		while (cur < n)
		{
			cur += 1.0 / div;
			div += 1.0;
			ans++;
		}
		cout << ans << " card(s)\n";

	}


	return 0;
}