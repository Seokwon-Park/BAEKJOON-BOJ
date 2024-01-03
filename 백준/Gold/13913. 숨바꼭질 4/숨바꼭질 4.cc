#include <bits/stdc++.h>

using namespace std;

int n, k;
bool visited[200005];
int prev_pos[200005];
int moved[200005];


void bfs(int n)
{
	fill(prev_pos, prev_pos + 200005, -1);
	queue<int> q;
	q.push(n);
	visited[n] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == k) break;
		for (int nxt : {cur - 1, cur + 1, cur * 2})
		{
			if (nxt < 0 || nxt >200000) continue;
			if (visited[nxt]) continue;
			visited[nxt] = true;
			prev_pos[nxt] = cur;
			moved[nxt] = moved[cur] + 1;
			q.push(nxt);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	bfs(n);

	stack<int> s;
	int ix = k;
	s.push(k);
	while (prev_pos[ix] != -1)
	{
		s.push(prev_pos[ix]);
		ix = prev_pos[ix];
	}
	cout << moved[k] << '\n';
	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}

	return 0;
}