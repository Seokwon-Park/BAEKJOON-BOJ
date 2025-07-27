#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;
template <typename key, typename value>
using hashm = unordered_map<key, value>;

vector<int> adj[200005];
bool v[200005];

int mxdist;
int mxnode;

void bfs(int st)
{
	queue<int> q;
	q.push(st);
	v[st] = true;
	int d = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i <qs; i++)
		{
			int cur = q.front();
			q.pop();
			mxnode = cur;
			for (int nxt : adj[cur])
			{
				if (v[nxt])continue;
				q.push(nxt);
				v[nxt] = true;
			}
		}
		d++;
	}
	mxdist = d - 1;
}

vector<int> find(int st, int d)
{
	queue<int> q;
	q.push(st);
	int dist = 0;
	vector<int> ret;
	v[st] = true;
	while (!q.empty())
	{
		dist++;
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			int cur = q.front();
			q.pop();
			for (int nxt : adj[cur])
			{
				if (v[nxt])continue;
				if (dist == d)
				{
					ret.push_back(nxt);
				}
				q.push(nxt);
				v[nxt] = true;
			}
		}
		if (d == dist)break;
	}
	return ret;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> roots;
	vector<int> leafs;
	for (int i = 1; i <= n; i++)
	{
		if (adj[i].size() == 1)
		{
			leafs.push_back(i);
		}
		if (adj[i].size() == 3)
		{
			roots.push_back(i);
		}
		if (adj[i].size() != 1 && adj[i].size() != 3)
		{
			cout << -1;
			return 0;
		}
	}

	int tmp = (n + 2) / 3;
	int d = 0;
	while (tmp != 1)
	{
		if (tmp % 2 != 0)
		{
			cout << -1;
			return 0;
		}
		tmp /= 2;
		d++;
	}

	bfs(1);
	fill(v, v + n + 1, false);
	tmp = mxnode;
	bfs(mxnode);
	
	if (mxdist != d * 2)
	{
		cout << -1;
		return 0;
	}

	fill(v, v + n + 1, false);
	vector<int> v1 = find(tmp, d);

	fill(v, v + n + 1, false);
	vector<int> v2 = find(mxnode, d);


	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	vector<int> res(1);
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(),res.begin());
	
	if (res.empty())
	{
		cout << -1;
	}
	else
	{
		cout << 1 << '\n' << res[0];
	}

	return 0;
}
