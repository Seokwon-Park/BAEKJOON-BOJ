#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int v[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, n, m;
	cin >> a >> b >> n >> m;

	queue<int> q;
	q.push(n);
	v[n] = true;
	int times = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			int cur = q.front();
			q.pop();
			for (int nxt : {cur+1, cur-1, cur-a, cur - b, cur + a, cur + b, cur* a, cur* b})
			{
				if (nxt < 0 || nxt > 100000 || v[nxt]) continue;
				if (nxt == m)
				{
					cout << times + 1;
					return 0;
				}
				q.push(nxt);
				v[nxt] = true;
			}
		}
		times++;
	}



	return 0;
}