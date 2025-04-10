#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

vector<int> adj[15];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i = 0; i < 12; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for (int i = 1; i <= 12; i++)
	{
		if (adj[i].size() != 3) continue;
		vector<int> v;
		for (int nxt : adj[i])
		{
			v.push_back(adj[nxt].size());
		}
		sort(v.begin(), v.end());
		if (v[0] == 1 && v[1] == 2 && v[2] == 3)
		{
			cout << i;
			break;
		}
	}
	
	return 0;
}