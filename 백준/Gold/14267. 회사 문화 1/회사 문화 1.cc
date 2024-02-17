#include <bits/stdc++.h>

using namespace std;

vector<int> junior[100005];

int good[100005];

void bfs(int node)
{
	queue<int> q;
	q.push(node);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int nxt : junior[cur])
		{
			good[nxt] += good[cur];
			q.push(nxt);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int ceo = 0;
	for (int i = 1; i <= n; i++)
	{
		int ix;
		cin >> ix;
		if (ix == -1)
		{ 
			ceo = i;
			continue;
		}
		junior[ix].push_back(i); // i번의 직속 상사는 ix 그러면 ix가 칭찬 받으면 i도 같이 받아야한ㄷ나.
	}

	for (int j = 0; j < m; j++)
	{
		int i, w;
		cin >> i >> w;
		good[i] += w;
	}
	bfs(ceo);


	for (int i = 1; i <= n; i++)
	{
		cout << good[i] << ' ';
	}


	return 0;
}