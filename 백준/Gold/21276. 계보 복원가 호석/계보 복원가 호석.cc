#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1005];
int deg[1005];
int p[1005];
vector<string> c[1005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_map<string, int> pton;
	unordered_map<int, string> ntop;

	int n;
	cin >> n;
	vector<string> namelist;
	for (int i = 1; i <= n; i++)
	{
		string name;
		cin >> name;
		namelist.push_back(name);
		pton[name] = i;
		ntop[i] = name;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string x, y;
		cin >> x >> y;
		int xn = pton[x];
		int yn = pton[y];
		if(p[xn] == 0)
			p[xn] = yn;
		else
		{

		}

		adj[xn].push_back(yn);
		deg[yn]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		//자신의 인접한 것들 중 가장 indegree가 적은 것을 찾아서 부모로 설정
		int parent = 0; // 부모 후보.
		int deg_min = INT_MAX;
		for (int nxt : adj[cur])
		{
			if (deg_min > deg[nxt])
			{
				deg_min = deg[nxt];
				parent = nxt;
			}
			deg[nxt]--;
			if (deg[nxt] == 0)
			{
				q.push(nxt);
			}
		}
		p[cur] = parent;
		c[parent].push_back(ntop[cur]);
	}

	int cnt = 0;
	vector<string> roots;
	for (int i = 1; i <= n; i++)
	{
		if (p[i] == 0)
		{
			cnt++;
			roots.push_back(ntop[i]);
		}
	}

	cout << cnt << '\n';
	sort(roots.begin(), roots.end());
	for (auto s : roots)
	{
		cout << s << ' ';
	}
	cout << '\n';

	sort(namelist.begin(), namelist.end());

	for (auto n : namelist)
	{
		cout << n << ' ' << c[pton[n]].size() << ' ';
		sort(c[pton[n]].begin(), c[pton[n]].end());
		for (auto s : c[pton[n]])
		{
			cout << s << ' ';
		}
		cout << '\n';
	}


	return 0;
}