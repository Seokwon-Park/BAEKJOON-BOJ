#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pii> v(n);
	for (int i = 0; i < n; i++)
	{
		int st, en;
		cin >> st >> en;
		v[i] = { st,en };
	}
	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<int>> pq;

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		auto [st, en] = v[i];
		if(pq.empty())
			pq.push(en);
		else
		{
			int enn = pq.top();
			if (enn <= st)
				pq.pop();
			pq.push(en);
		}
		ans = max(ans, (int)pq.size());
	}
	cout << ans;

	return 0;
}
