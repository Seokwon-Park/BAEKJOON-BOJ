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

	int n, m;
	cin >> n >> m;

	vector<int> v(n+2);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	vector<int> pfmin(n+2, INF);
	vector<int> pfmax(n+2, -INF);
	for (int i = 1; i <= n; i++)
	{
		pfmin[i] = min(pfmin[i-1], v[i]);
		pfmax[n-i+1] = max(pfmax[n-i+2], v[n-i+1]);
	}

	int ans = -INF;
	for (int i = 0; i <= m; i++)
	{
		ans = max(ans, pfmax[n - m + i] - pfmin[i+1]);
	}
	cout << ans;


	return 0;
}