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
	vector<ll> pow2(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	ll ans = 0;
	for (int i = 1; i < n; i++)
	{
		pow2[i] = max((int)ceil(log2((double)v[i - 1] / (double)v[i]) + pow2[i - 1]), 0);
		ans += pow2[i];
	}
	cout << ans;

	return 0;
}
