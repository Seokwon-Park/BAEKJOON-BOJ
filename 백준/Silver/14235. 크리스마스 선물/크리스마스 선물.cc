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
	while (n--)
	{
		int a;
		cin >> a;
		if (a == 0)
		{
			if (pq.empty())
			{
				cout << -1;
			}
			else
			{
				cout << pq.top();
				pq.pop();
			}
			cout << '\n';	
		}
		else
		{
			for (int i = 0; i < a; i++)
			{
				int m;
				cin >> m;
				pq.push(m);
			}
		}
	}

	return 0;
}
