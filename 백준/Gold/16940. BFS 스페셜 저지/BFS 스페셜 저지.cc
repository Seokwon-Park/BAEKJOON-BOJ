#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int n;
vector<int> adj[100005];
int v[100005];
int arr[100005];

bool bfs()
{
	set<int> s;
	queue<int> q;
	q.push(1);
	v[1] = true;
	int cursor = 0;
	if (arr[cursor++] != 1) // 일단 1로 시작안하면 틀림
		return false;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int nxt : adj[cur])
		{
			if (v[nxt]) continue;
			v[nxt] = true;
			s.insert(nxt);
		}
		while (s.find(arr[cursor]) != s.end())
		{
			q.push(arr[cursor]);
			s.erase(arr[cursor]);
			cursor++;
		}
		if (!s.empty()) return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << bfs();

	return 0;
}