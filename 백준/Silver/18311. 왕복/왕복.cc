#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, k;
	cin >> n >> k;
	vector<ll> pfsum(1, 0);
	vector<ll> v;
	for (int i = 1; i <= n; i++)
	{
		ll m;
		cin >> m;
		v.push_back(m);
		pfsum.push_back(pfsum[i - 1]+m);
	}

	for (int i = 0; i < n; i++)
	{
		pfsum.push_back(pfsum[pfsum.size() - 1] + v[n - 1 - i]);
	}

	for (int i = 1; i < pfsum.size(); i++)
	{
		if (pfsum[i] > k)
		{
			if (i <= n)
			{
				cout << i;
				return 0;
			}
			else
			{
				cout << n * 2 - i + 1;
				return 0;
			}
		}
	}


	return 0;
}