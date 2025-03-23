#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;






int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> adj(n * n, vector<int>());
	vector<int> deg(n * n, 0);
	vector<vector<int>> result(n, vector<int>(n, 0));


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			char c;
			cin >> c;
			if (c == '>')
			{
				adj[i * n + j + 1].push_back(i * n + j);
				deg[i * n + j]++;
			}
			else
			{
				adj[i * n + j].push_back(i * n + j + 1);
				deg[i * n + j + 1]++;
			}
		}
	}


	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			if (c == '>')
			{
				adj[(i + 1) * n + j].push_back(i * n + j);
				deg[i * n + j]++;
			}
			else
			{
				adj[i * n + j].push_back((i + 1) * n + j);
				deg[(i + 1) * n + j]++;
			}
		}
	}

	queue<int> q;
	for (int i = 0; i < n * n; i++)
	{
		if (deg[i] == 0)
		{
			q.push(i);
		}
	}

	int val = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		int r = cur / n;
		int c = cur % n;
		result[r][c] = val++;
		for (int nxt : adj[cur])
		{
			deg[nxt]--;
			if (deg[nxt] == 0)
			{
				q.push(nxt);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}