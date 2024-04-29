#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

vector<int> v(1, 0);
vector<int> tetra(1, 0);
int dp[300005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int d = 1;
	while (v[v.size() - 1] + d <= 300000)
	{
		v.push_back(v[v.size() - 1] + d);
		d++;
	}

	while (tetra.size() < v.size() && tetra[tetra.size() - 1] + v[tetra.size()] <= n)
	{
		tetra.push_back(tetra[tetra.size() - 1] + v[tetra.size()]);
	}

	fill(dp, dp + n+1, 0x3f3f3f);
	for (auto i : tetra)
	{
		dp[i] = 1;
	}

	for (int i = 1; i <= 300000; i++)
	{
		for (int j = 0; j<tetra.size(); j++)
		{
			if (tetra[j] >= i)break;
			dp[i] = min(dp[i], dp[i - tetra[j]] + 1);
		}
	}

	cout << dp[n];


	return 0;
}
