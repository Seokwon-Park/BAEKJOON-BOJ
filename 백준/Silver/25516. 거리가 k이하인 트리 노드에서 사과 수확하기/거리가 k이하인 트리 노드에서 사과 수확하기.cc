#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

vector<int> child[100005];
bool v[100005];
bool apple[100005];
int n, k;

int bfs()
{
	queue<int> q;
	q.push(0);
	v[0] = true;
	int dist = 0;
	int res = 0;
	while (!q.empty() && dist <= k)
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			int cur = q.front();
			res += apple[cur];
			q.pop();
			for (int nxt : child[cur])
			{
				q.push(nxt);
			}
		}
		dist++;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n-1; i++)
	{
		int p, c;
		cin >> p >> c;
		child[p].push_back(c);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> apple[i];
	}

	cout << bfs();

	return 0;
}
