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

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++)
	{
		int st, en;
		cin >> st >> en;
		auto lb = lower_bound(v.begin(), v.end(), st);
		auto ub = upper_bound(v.begin(), v.end(), en);
		cout << ub - lb << '\n';
	}

	return 0;
}