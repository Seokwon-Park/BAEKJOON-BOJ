#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int nxt[105];
int v[105];
int used[105];

vector<int> ans;

void dfs(int node)
{
	v[node] = true;
	if (!v[nxt[node]])
	{
		dfs(nxt[node]);
	}
	else // dfs 돌렸는데 방문한곳을 또방문한 경우 -> 사이클이 있다
	{
		if (!used[nxt[node]]) // 만약 탐색에 사용되지 않은 노드일 경우 추가한다.
		{
			ans.push_back(node);
			for (int i = nxt[node]; i != node; i = nxt[i])
			{
				ans.push_back(i);
			}
		}
	}
	used[node] = true; // 해당 노드는 이미 탐색에 사용한 것으로 변경한다.
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> nxt[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (!v[i])
			dfs(i);
	}

	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (int i : ans)
		cout << i << '\n';

	return 0;
}