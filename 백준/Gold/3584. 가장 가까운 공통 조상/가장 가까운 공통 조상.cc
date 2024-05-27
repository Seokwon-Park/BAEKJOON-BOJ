#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int dfs(int node, vector<int>& parent, int level)
{
	if (parent[node] == -1) return level;
		return dfs(parent[node], parent, level+1);
	
}

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
		vector<int> parent(n + 1, -1);
		for(int i =0;i <n -1;i ++)
		{
			int p, c;
			cin >> p >> c;
			parent[c] = p;
		}
		int a, b;
		cin >> a >> b;
		int alv = dfs(a, parent, 0);
		int blv = dfs(b, parent, 0);

		while (alv > blv)
		{
			a = parent[a];
			alv--;
		}
		while (blv > alv)
		{
			b = parent[b];
			blv--;
		}

		while (a != b)
		{
			a = parent[a];
			b = parent[b];
		}
		cout << a << '\n';
	}

	return 0;
}