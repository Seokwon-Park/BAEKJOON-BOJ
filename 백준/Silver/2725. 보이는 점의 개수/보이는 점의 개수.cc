#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dp[1005];
int pf[1005];

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	int mx = INT_MIN;
	vector<int> v;
	while (tc--)
	{
		int n;
		cin >> n;
		v.push_back(n);
		mx = max(n, mx);
	}
	for (int i = 0; i <= mx; i++)
	{
		for (int j = 0; j <= mx; j++)
		{
			int m = max(i, j);
			if (gcd(i, j) == 1)
				dp[m]++;
		}
	}
	for (int i = 1; i <= mx; i++)
	{
		pf[i] += pf[i-1] + dp[i];
	}

	for (auto i : v)
		cout << pf[i] << '\n';

	return 0;
}