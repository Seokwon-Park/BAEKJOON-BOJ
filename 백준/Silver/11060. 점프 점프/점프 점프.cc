#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

bool visited[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int& i : v)
		cin >> i;
	
	if (n == 1)
	{
		cout << 0;
		return 0;
	}

	queue<int> q;
	q.push(0);
	int jump = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int j = 0; j < qs; j++)
		{
			int cur = q.front(); q.pop();
			if (v[cur] == 0) continue;
			for (int i = 1; i <= v[cur]; i++)
			{
				if (visited[cur + i]) continue;
				if (cur + i == n - 1)
				{
					cout << jump + 1 << '\n';
					return 0;
				}
				visited[cur + i] = true;
				q.push(cur + i);
			}
		}
		jump++;
	}
	cout << -1;

	return 0;
}
