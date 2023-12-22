#include <bits/stdc++.h>

using namespace std;

int f, s, g, u, d;
vector<bool> visited;

int bfs()
{
	queue<pair<int,int>> q;
	q.push({ s, 0 });
	visited[s] = true;
	while (!q.empty())
	{
		int pos = q.front().first;
		int press = q.front().second;
		q.pop();
		for (auto target : { pos + u, pos - d })
		{
			if (target > f || target < 1) continue;
			if (visited[target]) continue;
			if (target == g)
			{
				return press + 1;
			}
			q.push({target, press+1});
			visited[target] = true;
		}
	}
	return -1;
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> f >>s>> g>> u>> d;
	
	visited.resize(f+5, false);
	
	if (s == g)
	{
		cout << 0;
		return 0;
	}

	int res = bfs();
	if (res == -1) cout << "use the stairs";
	else cout << res;




	return 0;
}