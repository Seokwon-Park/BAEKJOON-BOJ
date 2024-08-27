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

	int n, h, t;
	cin >> n >> h >> t;

	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		pq.push(m);
	}

	int ans = 0;
	while (pq.top() >= h && ans < t)
	{
		int a = pq.top();
		pq.pop();
		a = max(a / 2, 1);
		pq.push(a);
		ans++;
	}

	if (pq.top() < h)
	{
		cout << "YES\n";
		cout << ans;
	}
	else
	{
		cout << "NO\n";
		cout << pq.top();
	}
	
	return 0;
}