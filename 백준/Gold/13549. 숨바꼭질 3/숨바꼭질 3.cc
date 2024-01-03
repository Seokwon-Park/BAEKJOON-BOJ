#include <bits/stdc++.h>

using namespace std;

int n, k;
bool visited[200005];
int moved[200005];
int answer;

int shortest = -1;

void bfs(int n)
{
	queue<int>q;
	q.push(n);
	visited[n] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto nxt : { make_pair(cur * 2,0), make_pair(cur - 1, 1), make_pair(cur + 1,1),})
		{
			if (nxt.first < 0 || nxt.first >200000) continue;
			if (visited[nxt.first]) continue;
			if (moved[nxt.first] == 0)
			{
				moved[nxt.first] = moved[cur] + nxt.second;
				visited[nxt.first] = true;
				q.push(nxt.first);
			}
			else
			{
				moved[nxt.first] = min(moved[nxt.first], moved[cur] + nxt.second);
			}


		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	bfs(n);

	cout << moved[k];

	return 0;
}