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
	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		pq.push(m);
	}

	int ans = 0;
	while (pq.size() >1)
	{
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		a--;
		b--;
		if (a != 0)
			pq.push(a);
		if (b != 0)
			pq.push(b);
		ans++;
	}

	if (!pq.empty())
		ans += pq.top();

	if (ans > 1440)
		cout << -1;
	else
		cout << ans;

	return 0;
}