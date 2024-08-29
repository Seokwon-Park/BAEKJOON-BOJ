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
	
	int n, m, k;
	cin >> n >> m >> k;

	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		int d;
		cin >> d;
		pq.push(d);
	}

	int y = 0;
	vector<int> ans;
	
	while (!pq.empty())
	{
		int p = pq.top();
		pq.pop();
		ans.push_back(y / 2 + p);
		y = y / 2 + p;
		p -= m;
		if (p > k)
			pq.push(p);
	}

	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i << '\n';

	return 0;
}