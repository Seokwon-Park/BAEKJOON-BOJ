#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
//const int MOD = 1'000'000'007;
const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m, a, k;
	cin >> n >> m >> a >> k;

	ll x = a - k;
	ll mx = min(n, x + 1);
	ll mn = max(1LL, x / m + (x % m != 0) + 1LL);
	cout << mx << ' ' << mn;
	
	return 0;
}