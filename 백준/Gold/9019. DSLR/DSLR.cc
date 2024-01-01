#include <bits/stdc++.h>

using namespace std;

int target;

bool visited[10005];
string order[10005];

char cmd[4] = { 'D', 'S', 'L', 'R' };

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty())
	{
		int n = q.front();
		if (n == target)
		{
			cout << order[target] << '\n';
			break;
		}
		q.pop();
		int i = -1;
		for (int nxt : {n*2%10000, n-1 <0? 9999:n-1, n/1000+n*10 %10000, (n%10)*1000+n/10})
		{
			i++;
			if (visited[nxt]) continue;
			q.push(nxt);
			visited[nxt] = true;
			order[nxt] = order[n] + cmd[i];
		}
	}	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int start;
		cin >> start >> target;

		fill(visited, visited + 10005, false);
		fill(order, order + 10005, "");

		bfs(start);

	}
		
	return 0;
}