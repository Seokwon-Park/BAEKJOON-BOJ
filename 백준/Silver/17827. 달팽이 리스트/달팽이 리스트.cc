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

int g[200005];

int main()
{ 
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < n; i++)
	{
		cin >> g[i];
	}

	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		if (k < n)
		{
			cout << g[k] << '\n';
		}
		else
		{
			int cycle = n - v + 1;
			int mod = (k - n) % cycle;
			cout << g[v - 1 + mod] << '\n';
		}
	}

	return 0;
}