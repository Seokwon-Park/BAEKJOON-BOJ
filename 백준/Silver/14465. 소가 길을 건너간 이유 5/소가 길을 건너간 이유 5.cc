#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, b;
	cin >> n >> k >> b;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++)
	{
		v[i] = i;
	}
	for (int i = 0; i < b; i++)
	{
		int m;
		cin >> m;
		v[m] = -1;
	}

	int ans = INT_MAX;
	int needfix = 0;
	for (int i = 1; i <= k; i++)
	{
		if (v[i] == -1)
			needfix++;
	}

	ans = min(needfix,ans);

	for (int i = 2; i <= n - k+1; i++)
	{
		if (v[i - 1] == -1)
			needfix--;
		if (v[i + (k-1)] == -1)
			needfix++;
		ans = min(ans, needfix);
	}

	cout << ans;

	return 0;
}