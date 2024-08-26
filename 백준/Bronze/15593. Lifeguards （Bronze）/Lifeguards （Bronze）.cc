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

	vector<pii> v;
	for (int i = 0; i < n; i++)
	{
		int st, en;
		cin >> st >> en;
		v.push_back({ st,en });
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		vector<bool> range(1001, false);
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			auto [st, en] = v[j];
			fill(range.begin() + st, range.begin() + en, true);
		}
		ans = max(ans, (int)count(range.begin(), range.end(), true));
	}

	cout << ans;


	return 0;
}