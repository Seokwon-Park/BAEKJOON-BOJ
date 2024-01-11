#include <bits/stdc++.h>

using namespace std;

vector<int> p(305, -1);
int graph[305][305];

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool is_diff(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (p[a] == p[b]) p[a]--;
	if (p[a] < p[b]) p[b] = a;
	else p[a] = b;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> wi(n+1); // i번 논을 파는데 드는 비용
	for (int i = 1; i <= n; i++)
	{
		cin >> wi[i];
	}

	for (int i = 1; i <= n; i++)
	{
		graph[n + 1][i] = wi[i];
		graph[i][n + 1] = wi[i];
		for (int j = 1; j <= n; j++)
		{
			cin >> graph[i][j];
		}
		
	}

	vector<tuple<int, int, int>> edge;
	for (int i = 1; i <= n+1; i++)
	{
		for (int j = i; j <= n+1; j++)
		{
			edge.push_back(tie(graph[i][j], i, j));
		}
	}

	sort(edge.begin(), edge.end());

	int cnt = 0;
	int answer = 0;
	for(int i = 0; i <edge.size(); i++)
	{
		int a, b, cost;
		tie(cost, a, b) = edge[i];
		if (!is_diff(a, b))continue;
		answer += cost;
		cnt++;
		if (cnt == n) break;
	}

	cout << answer;

	return 0;
}