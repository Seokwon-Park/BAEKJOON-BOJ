#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

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
	ll nxt = 1;
	for (int i = n - 2; i >= 0; i--)
	{
		if (v[i] >= nxt + 1)
		{
			nxt++;
		}
		else
		{
			nxt = v[i];
		}
		ans += nxt;
	}
	cout << ans;


	return 0;
}