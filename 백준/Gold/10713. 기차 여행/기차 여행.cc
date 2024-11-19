#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

ll v[100005][3];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	int cur;
	cin >> cur;
	vector<ll> d(n+1);
	for (int i = 0; i < m-1; i++)
	{
		int nxt;
		cin >> nxt;
		if (cur < nxt)
		{
			d[cur] += 1;
			d[nxt] -= 1;
		}
		else
		{
			d[nxt] += 1;
			d[cur] -= 1;
		}
		cur = nxt;
	}

	vector<ll> pfsum(n);
	for (int i = 1; i < n; i++)
	{
		pfsum[i] = pfsum[i - 1] + d[i];
	}

	for (int i = 1; i <= n - 1; i++)
	{
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	}

	ll ans = 0;
	for (int i = 1; i <= n-1; i++)
	{
		ll x = pfsum[i];
		if (x * v[i][0] < v[i][2] + x * v[i][1])
		{
			ans += x * v[i][0];
		}
		else
		{
			ans += v[i][2] + x * v[i][1];
		}
	}

	cout << ans;



	return 0;
}