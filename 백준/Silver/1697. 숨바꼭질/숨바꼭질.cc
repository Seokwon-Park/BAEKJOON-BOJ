
#include <bits/stdc++.h>

using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int dist[200005];

	queue<int> q;

	fill(dist, dist + 100001, -1);

	int n, k;
	cin >> n >> k;
	
	q.push(n);
	dist[n] = 0;
	while (!q.empty())
	{
		auto pos = q.front();
		q.pop();
		if (pos == k)
		{
			cout << dist[pos];
			return 0;
		}
		for (int i : {pos-1, pos+1, pos*2})
		{
			if (i < 0 || i > 100000) continue;
			if (dist[i] != -1) continue;
			dist[i] = dist[pos] + 1;
			q.push(i);
		}	
	}

	return 0;
}