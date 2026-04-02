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

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	priority_queue<pii> pq;
	priority_queue<pii> nxt;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		pq.push({ v[i], i });
	}

	vector<int> ans(n);
	nxt.push({ pq.top().first, pq.top().second + 1 });
	ans[pq.top().second] = 0;
	pq.pop();
	int copied = 0;
	while(!pq.empty())
	{
		auto [x, loc] = pq.top();
		pq.pop();
		if (nxt.top().first - x >= k)
		{
			copied++;
			ans[loc] = nxt.top().second;
			nxt.push({ x,loc + 1 });
			if (copied == 2)
			{
				nxt.pop();
				copied = 0;
			}
		}
		else
		{
			cout << -1;
			return 0;
		}
	}
	for (int i : ans)
	{
		cout << i << ' ';
	}

	return 0;
}
