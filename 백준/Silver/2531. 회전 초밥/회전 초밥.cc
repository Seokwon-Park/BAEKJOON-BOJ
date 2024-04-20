#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

bool dp[55][1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	unordered_map<int, int> um;
	int n, d, k, c;
	cin >> n >> d >> k >> c;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < k; i++)
	{
		um[v[i]]++;
	}

	int ans = um.size();
	if (um.find(c) == um.end())
	{
		ans++;
	}
	for (int i = 1; i < n; i++)
	{
		um[v[i - 1]]--;
		if(um[v[i-1]] == 0)
			um.erase(v[i - 1]);
		um[v[(i + k - 1)%n]]++;
		if (um.find(c) == um.end())
		{
			ans = max((int)um.size() + 1, ans);
		}
		else
		{
			ans = max((int)um.size(), ans);
		}
	}

	cout << ans;

	return 0;
}