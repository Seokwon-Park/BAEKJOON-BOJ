#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adjbest[1005];
vector<pair<int, int>> adjworst[1005];
bool chkbest[1005];
bool chkworst[1005];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m+1; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		adjbest[a].push_back({ !cost, b });
		adjbest[b].push_back({ !cost, a });	
		adjworst[a].push_back({ cost, b });
		adjworst[b].push_back({ cost, a });
	}

	priority_queue<tuple<int, int, int>, vector< tuple<int, int, int>>, greater< tuple<int, int, int>>>pq;

	chkbest[0] = true;
	for (auto [cost, v] : adjbest[0])
	{
		pq.push({ cost, 0, v });
	}


	int bcnt = 0;
	int bk = 0;
	while (bcnt < n)
	{
		int cost, a, b;
		tie(cost, a, b) = pq.top();
		pq.pop();
		if (chkbest[b]) continue;
		chkbest[b] = true;
		bcnt++;
		bk += cost;
		for (auto [nxtc, nxt] : adjbest[b])
		{
			if (!chkbest[nxt])
			{
				pq.push({ nxtc, b, nxt });
			}
		}
	}
	
	while (!pq.empty())
	{
		pq.pop();
	}

	chkworst[0] = true;
	for (auto [cost, v] : adjworst[0])
	{
		pq.push({ cost, 0, v });
	}

	int wcnt = 0;
	int wk = 0;
	while (wcnt < n)
	{
		int cost, a, b;
		tie(cost, a, b) = pq.top();
		pq.pop();
		if (chkworst[b]) continue;
		chkworst[b] = true;
		wcnt++;
		wk += !cost;
		for (auto [nxtc, nxt] : adjworst[b])
		{
			if (!chkworst[nxt])
			{
				pq.push({ nxtc, b, nxt });
			}
		}
	}

	cout << wk*wk - bk*bk;
	return 0;
}
