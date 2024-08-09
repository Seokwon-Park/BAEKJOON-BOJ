#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int b[105][105];
pii st[105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int h, w;
	int n;
	cin >> h >> w >> n;

	
	for (int i = 0; i < n; i++)
	{
		int r, c;
		cin >> r >> c;
		st[i] = {r, c};
	}
	if (n == 1)
	{
		cout << 0;
		return 0;
	}

	vector<int> c(n, 0);
	fill(c.begin(), c.begin() + 2, 1);

	int ans = 0;
	do
	{
		vector<pii> rc;
		for (int i = 0; i < n; i++)
		{
			if (c[i])
			{
				rc.push_back(st[i]);
			}
		}
		int lefth = h - rc[0].first;
		int leftw = w - rc[0].second;
		int area = rc[0].first * rc[0].second + rc[1].first * rc[1].second;
		if (lefth >= 0 && leftw >= 0)
		{
			if (lefth >= rc[1].first && w >= rc[1].second)
			{
				ans = max(ans, area);
			}
			else if (leftw >= rc[1].second && h >= rc[1].first)
			{
				ans = max(ans, area);
			}
			else if (lefth >= rc[1].second && w >= rc[1].first)
			{
				ans = max(ans, area);
			}
			else if (leftw >= rc[1].first && h >= rc[1].second)
			{
				ans = max(ans, area);
			}
		}

		lefth = h - rc[0].second;
		leftw = w - rc[0].first;
		if (lefth >= 0 && leftw >= 0)
		{
			if (lefth >= rc[1].first && w >= rc[1].second)
			{
				ans = max(ans, area);
			}
			else if (leftw >= rc[1].second && h >= rc[1].first)
			{
				ans = max(ans, area);
			}
			else if (lefth >= rc[1].second && w >= rc[1].first)
			{
				ans = max(ans, area);
			}
			else if (leftw >= rc[1].first && h >= rc[1].second)
			{
				ans = max(ans, area);
			}
		}
	} while (prev_permutation(c.begin(), c.end()));
	cout << ans;

	return 0;
}