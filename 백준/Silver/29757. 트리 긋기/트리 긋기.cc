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
	vector<pair<pii, int>> v(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[i] = { { x, y }, i + 1 };
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n-1; i++)
	{
		auto [p, ix] = v[i];
		auto [np, nix] = v[i+1];
		cout << ix << ' ' << nix << '\n';
	}

	return 0;
}
