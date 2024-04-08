#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

bool visited[1005];
int adj[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		fill(visited, visited + 1005, false);
		fill(adj, adj + 1005, 0);
		int n;
		cin >> n;
		vector<int> v(n);
		for (int& i : v)
			cin >> i;
		vector<int> sorted = v;
		sort(sorted.begin(), sorted.end());
		
		for (int i = 0; i < n; i++)
		{
			adj[sorted[i]] = v[i];
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (visited[i]) continue;
			int cur = i;
			while (!visited[cur])
			{
				visited[cur] = true;
				cur = adj[cur];
			}
			cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}