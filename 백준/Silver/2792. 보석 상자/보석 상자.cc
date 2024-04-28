#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v(m);
	for (int i = 0; i < m; i++)
	{
		cin >> v[i];
	}
	
	int st = 1;
	int ed = INT_MAX/2;
	while (st < ed)
	{
		int mid = (st + ed)/2;
		int cnt = 0;
		for (int i = 0; i < m; i++)
		{
			cnt += v[i] / mid;
			cnt += (v[i] % mid != 0 ? 1 : 0);
		}

		if (cnt > n)
		{
			st = mid+1;
		}
		else
		{
			ed = mid;
		}
	}

	cout << st;

	return 0;
}