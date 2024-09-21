#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int n, m;
int v[5005];

bool solve(int mid)
{
	int cnt = 0;
	int mx = v[0];
	int mn = v[0];
	for (int i = 1; i < n; i++)
	{
		mx = max(mx, v[i]);
		mn = min(mn, v[i]);
		if (mx - mn > mid)
		{
			mx = v[i];
			mn = v[i];
			cnt++;
		}
	}
	cnt += 1;

	return cnt > m;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int st = 0;
	int en = 20000;
	while (st < en)
	{
		int mid = (st + en) / 2;
		if (solve(mid))
		{
			st = mid+1;
		}
		else
		{
			en = mid;
		}
	}

	cout << st;

	return 0;
}