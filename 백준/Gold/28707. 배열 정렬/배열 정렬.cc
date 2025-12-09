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
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int m;
	cin >> m;
	vector<tiii> op(m);
	for (int i = 0; i < m; i++)
	{
		int l, r, c;
		cin >> l >> r >> c;
		l--; r--;
		op[i] = tie(l, r, c);
	}

	map<vector<int>, int> d;
	using T = pair<int, vector<int>>;
	priority_queue<T, vector<T>, greater<T>> pq;
	pq.push({ 0, v });
	d[v] = 0;
	while (!pq.empty())
	{
		auto [cost, cur] = pq.top();
		pq.pop();
		if (d[cur] != cost) continue;
		for (int i = 0; i < m; i++)
		{
			auto [l, r, c] = op[i];
			auto nxt = cur;
			int ncost = cost + c;
			swap(nxt[l], nxt[r]);
			if (d.find(nxt) == d.end())
			{
				d[nxt] = INF;
			}
			if (ncost < d[nxt])
			{
				d[nxt] = ncost;
				pq.push({ ncost, nxt });
			}
		}
	}

	/*for (auto [vec, cost] : d)
	{
		for (auto i : vec)
			cout << i << ' ';

		cout << " - " << cost << '\n';
	}*/

	sort(v.begin(), v.end());
	if (d.find(v) != d.end())
	{
		cout << d[v];
	}
	else
	{
		cout << -1;
	}


	return 0;
}