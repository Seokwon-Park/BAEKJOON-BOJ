#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

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

	pq.pop();
	int ans = 0;
	while (!pq.empty())
	{
		ans += pq.top();
		pq.pop();
	}
	cout << ans;


	return 0;
}
