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
	
	int t;
	cin >> t;
	for(int tc= 1; tc<=t; tc++)
	{
		int n, w, e;
		cin >> n >> w >> e;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			ans += max(w * a + e * c, w * b + e * d);
		}
		cout << "Data Set " << tc << ":\n" << ans << "\n\n";
	}

	return 0;
}
