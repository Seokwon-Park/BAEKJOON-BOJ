#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

// 3, -2, 0, -1, 3
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<ll> v(n+1);
	vector<ll> pfsum(n+1);

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		pfsum[i] = pfsum[i - 1] + v[i];
	}

	sort(pfsum.begin()+1, pfsum.end(), greater<ll>());
	ll  ans = 0;
	for (int i = 1; i <= k; i++)
	{
		ans += pfsum[i];
	}
	cout << ans;


	return 0;
}