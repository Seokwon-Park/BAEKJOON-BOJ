#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> bb(n+1);
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> bb[i];
	}

	int a, b;
	cin >> a >> b;

	if (a == b)
	{
		cout << 0;
		return 0;
	}

	queue<int> q;
	q.push(a);
	v[a] = 1;
	int dist = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			int cur = q.front();
			q.pop();
			for(int i = 1; i * bb[cur] <= n; i++)
			{
				int nxt = cur + i * bb[cur];
				int nxt2 = cur - i * bb[cur];
				if (nxt == b || nxt2 == b)
				{
					cout << dist + 1;
					return 0;
				}
				if (nxt <= n && !v[nxt])
				{
					q.push(nxt);
					v[nxt] = true;
				}

				if (nxt2 >= 1 && !v[nxt2])
				{
					q.push(nxt2);
					v[nxt2] = true;
				}
			}
		}
		dist++;
	}

	cout << -1;

	return 0;
}