#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, l;
	cin >> n >> l;

	vector<pii> v(n);
	for (int i = 0; i < n; i++)
	{
		int st, en;
		cin >> st >> en;
		v[i] = { st, en };

	}

	sort(v.begin(), v.end());

	int cur = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		auto [st, en] = v[i];
		if (en <= cur) continue;
		if (cur < st)
			cur = st;
		int len = en - cur;
		int need = len / l + (len % l == 0 ? 0 : 1);
		ans += need;
		cur += need * l;
	}

	cout << ans;

	return 0;
}