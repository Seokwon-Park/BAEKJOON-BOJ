#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

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

	ll ans = 1;
	
	for (int j = 0; j < n-1; j++)
	{
		ll sum = v[j];
		ll cur = 1;
		for (int i = j+1; i < n; i++)
		{
			if (sum >= v[i])
			{
				cur++;
				sum += v[i];
			}
			ans = max(ans, cur);
		}
	}

	cout << ans;

	return 0;
}



