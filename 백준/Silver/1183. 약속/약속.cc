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

	vector<ll> v;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(a - b);
	}

	vector<ll> res;
	for (int i = 0; i < n; i++)
	{
		ll t = -v[i];
		res.push_back(t);
	}

	sort(res.begin(), res.end());

	if (n% 2 == 1)
	{
		cout << 1;
	}
	else
	{
		cout << res[n / 2] - res[n / 2 - 1] + 1;
	}

	return 0;
}