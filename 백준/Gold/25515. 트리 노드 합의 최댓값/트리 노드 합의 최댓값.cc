#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

vector<int> child[100005];
int v[100005];

ll dfs(ll node)
{
	ll ret = v[node];
	for (int nxt : child[node])
	{
		ll res = dfs(nxt);
		if (res > 0)
		{
			ret += res;
		}
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
		int p, c;
		cin >> p >> c;
		child[p].push_back(c);
	}
	
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	cout << dfs(0);



	return 0;
}
