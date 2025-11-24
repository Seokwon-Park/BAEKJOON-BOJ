#include <bits/stdc++.h>

using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

bool adj[505][505];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		vector<int> rank(n+1);

		vector<int> degree(n + 1);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			rank[v[i]] = i;
		}

		for (int i = n-1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				adj[v[j]][v[i]] = true;
				degree[v[i]]++;
			}
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			if (rank[a] < rank[b]) // a가 더 앞선 순위였다면
			{
				adj[a][b] = false;
				adj[b][a] = true;
				degree[b]--;
				degree[a]++;
			}
			else
			{
				adj[b][a] = false;
				adj[a][b] = true;
				degree[a]--;
				degree[b]++;
			}
		}

		queue<int> q;
		for (int i = 1; i <= n; i++)
		{
			if (degree[i] == 0) q.push(i);
		}

		vector<int> ans;
		while (!q.empty())
		{
			int cur = q.front();
			ans.push_back(cur);
			q.pop();
			bool isCycle = true;
			for (int i = 1; i<= n; i++)
			{
				if (adj[cur][i])
				{
					degree[i]--;
					if (degree[i] == 0)
					{
						q.push(i);
					}
				}
			}
		}

		if (ans.size() != n)
		{
			cout << "IMPOSSIBLE";
		}
		else
		{
			for (int i : ans)
			{
				cout << i << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}