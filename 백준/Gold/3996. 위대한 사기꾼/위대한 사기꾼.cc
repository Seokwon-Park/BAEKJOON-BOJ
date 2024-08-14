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

	ll kk = k * k;
	vector<ll> v;
	while (n)
	{
		v.push_back(n % kk);
		n /= kk;
	}

	reverse(v.begin(), v.end());
	ll ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < k)
		{
			ans += v[i];
			ans *= k;
		}
		else
		{
			ans += k;
			for (int j = i; j < v.size(); j++)
			{
				ans *= k;
			}
			cout << ans / k;
			return 0;
		}
	}
	cout << ans / k+1;
	

	return 0;
}