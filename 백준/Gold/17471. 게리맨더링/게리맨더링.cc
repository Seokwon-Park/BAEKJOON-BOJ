#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

vector<int> adj[11];
bool v[11];
int b[11];

pii bfs(int node, vector<int>& comb, vector<int>& popul)
{
	queue<int> q;
	q.push(node);
	v[node] = true;
	int sz = 1;
	int total = popul[node];
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int nxt : adj[cur])
		{
			if (v[nxt] || comb[nxt] != comb[cur]) continue;
			v[nxt] = true;
			q.push(nxt);
			sz++;
			total += popul[nxt];
		}
	}
	return { sz, total };

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
		
	int n;
	cin >> n;
	vector<int> popul(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> popul[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		int adjSize;
		cin >> adjSize;
		for (int j = 0; j < adjSize; j++)
		{
			int v;
			cin >> v;
			adj[i].push_back(v);
		}
	}

	int ans = INT_MAX;
	for (int i = 1; i <= n - 1; i++)
	{
		vector<int> comb(n+1, 0);
		fill(comb.end() - i, comb.end(), 1);
		do
		{
			int asize = i;
			int bsize = n - i;
			pii atest;
			pii btest;
			fill(v, v + 11, false);
			for (int j = 1; j <= n; j++)
			{
				if (comb[j] == 0)
				{
					btest = bfs(j, comb, popul);
					break;
				}
			}

			for (int j = 1; j <= n; j++)
			{
				if (comb[j] == 1)
				{
					atest = bfs(j, comb, popul);
					break;
				}
			}

			if (atest.first == asize && btest.first == bsize)
			{
				ans = min(ans, abs(atest.second - btest.second));
			}
		} while (next_permutation(comb.begin()+1, comb.end()));
	}
	if (ans != INT_MAX)
		cout << ans;
	else
		cout << -1;


	return 0;
}