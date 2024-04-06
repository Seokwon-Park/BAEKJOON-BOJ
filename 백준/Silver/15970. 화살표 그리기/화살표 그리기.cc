#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> pts[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m, c;
		cin >> m >> c;
		pts[c].push_back(m);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(pts[i].begin(), pts[i].end());
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) // color
	{
		if (pts[i].empty())continue;
		ans += abs(pts[i][0] - pts[i][1]);
		for (int j = 1; j < pts[i].size()-1; j++)
		{
			ans += min(abs(pts[i][j - 1] - pts[i][j]),abs(pts[i][j + 1] - pts[i][j]));
		}
		ans += abs(pts[i][pts[i].size()-1] - pts[i][pts[i].size() - 2]);

	}
	cout << ans;

	return 0;
}