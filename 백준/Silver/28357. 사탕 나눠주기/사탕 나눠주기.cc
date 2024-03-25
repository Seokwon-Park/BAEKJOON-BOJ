#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll n, k;
vector<ll> v;

bool solve(ll x)
{
	ll res = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > x)
			res += v[i] - x;
	}
	return res <= k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		ll m;
		cin >> m; 
		v.push_back(m);
	}
	ll st = 0;
	ll ed = LLONG_MAX/2;
	while (st < ed)
	{
		ll mid = (st + ed) / 2;
		if (solve(mid))
			ed = mid;
		else
			st = mid+1;
	}
	cout << ed;

	return 0;
}