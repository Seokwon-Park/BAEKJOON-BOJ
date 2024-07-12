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

	int n, m;
	cin >> n >> m;

	vector<ll> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	ll sum = accumulate(v.begin(), v.begin()+m, 0LL);
	ll ans = sum;
	int st = 0;
	int en = m;
	while (en <n)
	{
		sum -= v[st];
		st++;
		sum += v[en];
		en++;
		ans = max(ans, sum);
	}
	cout << ans;


	return 0;
}