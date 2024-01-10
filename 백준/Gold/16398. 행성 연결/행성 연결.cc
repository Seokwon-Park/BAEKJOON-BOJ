#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[1005];
int board[1005][1005];
bool chk[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<tuple<int, int, int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> board[i][j];
			adj[i].push_back({ board[i][j], j });
		}
	}

	chk[1] = true;
	for (auto [cost, v] : adj[1])
	{
		pq.push({ cost, 1, v });
	}

	int cnt = 0;
	long long answer = 0;
	while (cnt < n - 1)
	{
		int cost, a, b;
		tie(cost, a, b) = pq.top();
		pq.pop();
		if (chk[b]) continue;
		chk[b] = true;
		cnt++;
		answer += cost;
		for (auto [cost, v] : adj[b])
		{
			pq.push({ cost, b, v });
		}
	}

	cout << answer;

	return 0;
}