#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<double,int>> v;
	for (int i = 1; i <= n; i++)
	{
		double x, y, vv;
		cin >> x >> y >> vv;
		double t = sqrt(x * x + y * y) / vv;
		v.push_back({ t, i });
	}
	stable_sort(v.begin(), v.end());

	for (auto [a, b] : v)
		cout << b << '\n';

	return 0;
}