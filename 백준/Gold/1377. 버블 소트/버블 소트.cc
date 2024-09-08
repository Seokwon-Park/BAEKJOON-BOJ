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
	vector<pair<int,int>> v;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		v.push_back({ m, i });
	}

	sort(v.begin(), v.end());

	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		auto [m, ix] = v[i];
		int moveToLeft = ix - i;
		ans = max(ans, 1 + moveToLeft);
	}
	cout << ans;


	return 0;
}