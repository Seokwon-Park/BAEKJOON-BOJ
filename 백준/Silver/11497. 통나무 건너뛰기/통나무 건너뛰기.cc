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
		int n;
		cin >> n;

		priority_queue<int> pq;
		for (int i = 0; i < n; i++)
		{
			int m;
			cin >> m;
			pq.push(m);
		}

		deque<int> dq;
		int ix = 0; 
		int ans = 0;
		while (!pq.empty())
		{
			if (dq.empty())
			{
				dq.push_back(pq.top());
				pq.pop();
			}
			else
			{
				if (pq.size() >= 2)
				{
					int a = pq.top(); pq.pop();
					int b = pq.top(); pq.pop();
					ans = max(abs(dq.front() - a), ans);
					dq.push_front(a);
					ans = max(abs(dq.back() - b), ans);
					dq.push_back(b);
				}
				else if (pq.size() == 1)
				{
					ans = max(abs(dq.front() - pq.top()), ans);
					ans = max(abs(dq.back() - pq.top()), ans);
					pq.pop();
				}
			}
		}
		cout << ans << '\n';
	}


	return 0;
}