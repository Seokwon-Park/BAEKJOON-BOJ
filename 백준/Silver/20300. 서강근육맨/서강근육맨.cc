#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	ll st = 0;
	ll en = n % 2 == 0 ? n - 1: n-2;
	ll ans = n % 2 == 0 ? 0 : v[n - 1];
	while (st < en)
	{
		ans = max(ans, v[st] + v[en]);
		st++;
		en--;
	}
	cout << ans;


	return 0;
}