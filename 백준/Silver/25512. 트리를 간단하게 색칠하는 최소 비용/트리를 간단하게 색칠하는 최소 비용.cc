#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<int> adj[100005];
int color[100005];
ll wCost[100005];
ll bCost[100005];
ll wb;
ll bw;

void SetColor()
{
	queue<int> q;
	q.push(0);
	color[0] = 0; // 0을 흰색으로 생각할건지 검은색으로 생각할건지->일단 0인 색깔부터 칠한다.
	wb = wCost[0];
	bw = bCost[0];
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int nxt : adj[cur])
		{
			
			color[nxt] = (color[cur] == 0 ? 1 : 0);
			if (color[nxt] == 1)
			{
				wb += bCost[nxt];
				bw += wCost[nxt];
			}
			else if(color[nxt] == 0)
			{
				wb += wCost[nxt];
				bw += bCost[nxt];
			}
			
			q.push(nxt);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	fill(color, color + n + 5, -1);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> wCost[i] >> bCost[i];
	}

	SetColor();

	cout << min(wb, bw);


	return 0;
}

