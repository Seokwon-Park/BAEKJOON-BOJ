#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int dp[100005][6];
int mx[6];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	int n;
	cin >> n;

	vector<pii> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i][v[i - 1].first] = dp[i - 1][v[i - 1].first] + 1;
		dp[i][v[i - 1].second] = dp[i - 1][v[i - 1].second] + 1;
	}

	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			mx[i] = max(mx[i], dp[j][i]);
		}
	}
	auto itr = max_element(mx + 1, mx + 6);
	cout << *itr << ' ' << itr - mx;

	return 0;
}