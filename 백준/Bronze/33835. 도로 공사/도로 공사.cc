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

	ll n;
	cin >> n;
	vector<pair<ll, ll>> v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}

	double x = v[0].first - v[n - 1].first;
	double y = v[0].second - v[n - 1].second;

	cout << fixed << setprecision(4) << sqrt(x * x + y * y);

	return 0;
}
