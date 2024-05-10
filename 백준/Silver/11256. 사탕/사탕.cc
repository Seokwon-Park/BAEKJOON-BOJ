#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		priority_queue<int> pq;
		int j, n;
		cin >> j >> n;
		for (int i = 0; i < n; i++)
		{
			int r, c;
			cin >> r >> c;
			pq.push(r * c);
		}

		int ans = 0;
		while (j > 0)
		{
			j -= pq.top();
			pq.pop();
			ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}
