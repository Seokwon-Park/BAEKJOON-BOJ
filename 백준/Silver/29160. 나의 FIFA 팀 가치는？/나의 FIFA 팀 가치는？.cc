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

	int n, k;
	cin >> n >> k;
	priority_queue<int> pq[11];
	for (int i = 0; i < n; i++)
	{
		int p, w;
		cin >> p >> w;
		pq[p - 1].push(w);
	}

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (pq[j].empty()) continue;
			int p = pq[j].top();
			pq[j].pop();
			pq[j].push(max(0, p - 1));
		}
	}

	ll ans = 0;
	for (int i = 0; i < 11; i++)
	{
		if (!pq[i].empty())
		{
			ans += pq[i].top();
		}
	}
	cout << ans;

	return 0;
}