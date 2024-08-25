#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int c[30005];
vector<int> p(30005, -1);
vector<int> sz(30005, 1);
bool isUsed[30005];

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (a > b)
		swap(a, b);
	p[b] = a;
	c[a] += c[b];
	sz[a] += sz[b];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		uni(a, b);
	} 


	vector<pii> v(1);
	int l = 0;
	for (int i = 1; i <= n; i++)
	{
		int tmp = find(i);
		if (isUsed[tmp]) continue;
		isUsed[tmp] = true;
		v.push_back({sz[tmp], c[tmp]});
		l++;
	}

	vector<vector<int>> dp(l+1, vector<int>(k));

	for (int i = 1; i <= l; i++)
	{
		auto [weight, value] = v[i];
		for (int j = 1; j < k; j++)
		{
			if (weight > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i - 1][j - weight] + value);
			}
		}
	}

	cout << dp[l][k-1];

	return 0;
}