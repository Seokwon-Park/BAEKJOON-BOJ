#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool visited[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a, p;
	cin >> a >> p;
	
	vector<int> v;
	queue<int> q;
	q.push(a);
	visited[a] = true;
	v.push_back(a);
	int ix = 0;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		int nxt = 0;
		while (cur)
		{
			int tmp = cur % 10;
			int res = 1;
			for (int i = 0; i < p; i++)
			{
				res *= tmp;
			}
			nxt += res;
			cur /= 10;
		}
		if (visited[nxt]) 
		{
			ix = find(v.begin(), v.end(), nxt) - v.begin();
			break;
		}
		visited[nxt] = true;
		q.push(nxt);
		v.push_back(nxt);
	}
	cout << ix; 

	return 0;
}