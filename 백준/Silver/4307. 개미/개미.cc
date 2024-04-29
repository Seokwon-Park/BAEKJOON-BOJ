#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int l, n;
		cin >> l >> n;

		int fast = 0;
		int mn = INT_MAX;
		int mx = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			int m;
			cin >> m;
			mn = min(m, mn);
			mx = max(m, mx);
			int res = min(l - m, m);
			fast = max(fast, res);
		}
		int slow = max(l - mx, mn) + mx - mn;


		cout << fast << ' ' << slow;
		cout << '\n';
	}

	return 0;
}