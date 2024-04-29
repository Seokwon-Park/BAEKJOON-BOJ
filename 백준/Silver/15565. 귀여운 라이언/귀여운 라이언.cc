#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> ryan;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		if(m == 1)
			ryan.push_back(i);
	}

	int st = 0;
	int ed = k - 1;
	int ans = INT_MAX;
	if (ryan.size() < k)
	{
		cout << -1;
		return 0;
	}
	else
	{
		while (ed < ryan.size())
		{
			int res = ryan[ed] - ryan[st] + 1;
			ans = min(ans, res);
			ed++;
			st++;
		}
		cout << ans;
	}

	return 0;
}
