#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

ll v[100005];
int n, m;

bool solve(ll mid)
{
	ll mm = 0;
	ll leftmoney = 0;
	for (int i = 0; i < n; i++)
	{
		if (mid < v[i]) return false;
		if (leftmoney < v[i])
		{
			leftmoney = mid; 
			mm++;
		}
		leftmoney -= v[i];
	}
	return mm <= m;
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

	ll st = 1;
	ll en = LLONG_MAX-1;

	while (st < en)
	{
		ll mid = (st + en) / 2;
		if (solve(mid))
		{
			en = mid;
		}
		else
		{
			st = mid+1;
		}
	}
	cout << st;

	return 0;
}