#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

ll pfsum[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<ll> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		pfsum[i] = pfsum[i - 1] + v[i];
	}

	ll ans = 0;
	for (int i = 1; i < n; i++)
	{
		ans += (pfsum[n]- pfsum[i]) * v[i];
	}
	cout << ans;

	return 0;
}