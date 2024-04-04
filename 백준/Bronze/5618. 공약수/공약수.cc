#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<ll> v(n);
	for (ll& i : v)cin >> i;
	int res = gcd(v[0], v[1]);
	if (v.size() > 2)
		res = gcd(res, v[2]);

	set<int> ans;
	for (int i = 1; i * i <= res; i++)
	{
		if (res % i == 0)
		{
			ans.insert(i);
			ans.insert(res / i);
		}
	}

	for (int i : ans)
		cout << i << '\n';

	return 0;
}
