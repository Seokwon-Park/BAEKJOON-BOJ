#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
		
	int n;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	ll mn = LLONG_MAX;
	vector<ll> ans(3);
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			int ix = lower_bound(v.begin(), v.end(), -(v[i] + v[j]))-v.begin();

			for (int k = -2; k <= 2; k++)
			{
				int res = ix + k;
				if (ix + k == i || ix + k == j)continue;
				if (ix + k < 0 || ix + k >= n)continue;
				if (mn > abs(v[i] + v[j] + v[ix + k]))
				{
					mn = abs(v[i] + v[j] + v[ix + k]);
					ans[0] = v[i];
					ans[1] = v[j];
					ans[2] = v[ix + k];
				}
			}
		}
	}

	sort(ans.begin(), ans.end());
	for (int i : ans)
		cout << i << ' ';

	return 0;
}