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

	int n, d;
	cin >> n;
	vector<pii> v(n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v[i] = { a, b };
	}
	cin >> d;
	vector<pii> v2;
	for (auto [s, t] : v)
	{
		if (s > t) swap(s, t);
		if (t - s <= d)
			v2.push_back({ s,t });
	}

	sort(v2.begin(), v2.end(), [](const auto& a, const auto& b) 
		{
			if (a.second == b.second)
			{
				return a.first < b.first;
			}
			return a.second < b.second;
		}
	);

	int ans = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < v2.size(); i++)
	{
		auto [s, t] = v2[i];
		pq.push(s);

		while (!pq.empty() && pq.top() < t - d)
		{
			pq.pop();
		}
		ans = max(ans, (int)pq.size());
	}
	cout << ans;

	return 0;
}