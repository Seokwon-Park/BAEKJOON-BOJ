#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pii> v;
	for (int i = 0; i < n; i++)
	{
		int s, e;
		cin >> s >> e;
		v.push_back({ s, 1 });
		v.push_back({ e,0 });
	}

	sort(v.begin(), v.end());

	int ans = 0;
	int cur = 0;
	for (int i = 0; i < v.size(); i++)
	{
		auto [x, y] = v[i];
		if (y == 1)
			cur++;
		else
			cur--;
		ans = max(ans, cur);
	}
	cout << ans;


	return 0;
}