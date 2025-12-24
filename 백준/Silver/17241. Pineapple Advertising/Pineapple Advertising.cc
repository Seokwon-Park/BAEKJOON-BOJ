#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

vector<int> adj[200005];
bool v[200005];
bool ischk[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < q; i++)
	{
		int x;
		cin >> x;
		int ans = 0;
		if (ischk[x])
		{
			cout << ans << '\n';
			continue;
		}
		ischk[x] = true;
		if (!v[x])
		{
			v[x] = true;
			ans = 1;
		}
		for (int nxt : adj[x])
		{
			if(!v[nxt])
			{
				v[nxt] = true;
				ans++;
			}
		}
		cout << ans << '\n';
	}


	return 0;
}