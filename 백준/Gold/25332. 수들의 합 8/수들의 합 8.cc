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

	int n;
	cin >> n;
	vector<ll> a(n+1), b(n+1), c(n+1), pfsum(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		c[i] = a[i] - b[i];
	}

	for (int i = 1; i <= n; i++)
	{
		pfsum[i] = pfsum[i - 1] + c[i];
	}

	map<ll, ll> m;
	ll ans = 0;
	for (int i = 0; i <= n; i++)
	{
		ans += m[pfsum[i]]++;
	}

	cout << ans;

	return 0;
}