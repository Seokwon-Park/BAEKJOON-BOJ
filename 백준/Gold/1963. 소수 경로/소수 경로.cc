#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

vector<bool> isPrime(10005, true);
int a, b;
bool visited[10005];

int bfs(int a)
{
	fill(visited, visited + 10005, false);
	queue<int> q;
	q.push(a);
	int dist = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int s = 0; s < qs; s++)
		{
			string cur = to_string(q.front()); q.pop();
			if (stoi(cur) == b) 
				return dist;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					string tmp = cur;
					tmp[i] = j + '0';
					int res = stoi(tmp);
					if (visited[res] || !isPrime[res]) continue;
					if (res < 1000) continue;
					visited[res] = true;
					q.push(res);
				}
			}
		}
		dist++;
	}
	return -1;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	isPrime[1] = false;

	int tc;
	cin >> tc;
	for (int i = 2; i * i < 10005; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i * i; j < 10005; j+= i)
		{
			isPrime[j] = false;
		}
	}
	while (tc--)
	{
		cin >> a >> b;

		int res = bfs(a);
		if (res == -1)
			cout << "Impossible\n";
		else
			cout << res << '\n';
	}
	
	return 0;
}
