#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
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

	vector<pii> v, vv;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		vv.push_back({ x,y });
	}

	auto [x1, y1] = *min_element(v.begin(), v.end());
	auto [x2, y2] = *min_element(vv.begin(), vv.end());
	cout << x2 - x1 << ' ' << y2 - y1;

	return 0;
}