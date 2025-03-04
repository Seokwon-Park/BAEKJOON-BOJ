#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;


 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m, k;
	cin >> n >> m >> k;

	priority_queue<pii,vector<pii>, greater<pii>> pq;
	for (int i = 0; i < k; i++)
	{
		int v, c;
		cin >> v >> c;
		pq.push({c, v});
	}

	priority_queue<pii, vector<pii>, greater<pii>> curpq;
	ll cur = 0;
	int curlv = 0;
	while (!pq.empty())
	{
		auto [c, v] = pq.top();
		curlv = c;
		if (curpq.size() < n)
		{
			cur += v;
			curpq.push({ v, c });
		}
		else
		{
			cur -= curpq.top().first;
			curpq.pop();
			curpq.push({v,c});
			cur += v;
		}
		pq.pop();
		if (cur >= m && curpq.size() == n)
		{
			break;
		}
	}

	if (m > cur)
	{
		cout << -1;
	}
	else
	{
		cout << curlv;
	}

	

	return 0;
}