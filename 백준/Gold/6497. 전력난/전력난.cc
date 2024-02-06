#include <bits/stdc++.h>

using namespace std;

vector<int> p(200005, -1);

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool isDiff(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return false;
	if (p[a] == p[b]) p[a]--;
	if (p[a] < p[b]) p[b] = a;
	else p[a] = b;
	return true;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true)
	{
		int n, m;
		cin >> n >> m;

		if (n == 0 && m == 0)
		{
			break;
		}

		vector<tuple<int, int, int>> edges(n);
		
		int tot = 0;
		for (int i = 0; i < m; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			tot += z;
			edges.push_back(tie(z, x, y));
		}

		sort(edges.begin(), edges.end());

		int cnt = 0;
		int mst = 0;
		for (int i = 0; i < edges.size(); i++)
		{
			int a, b, cost;
			tie(cost, a, b) = edges[i];
			if (isDiff(a, b)) // 연결 해야 되면. 연결하고 mst 갱신
			{
				cnt++;
				mst += cost;
			}
			if (cnt == n - 1) break;
		}


		//cout << mst;
		cout << tot - mst << '\n';
		fill(p.begin(), p.end(), -1);
	}

	return 0;
}