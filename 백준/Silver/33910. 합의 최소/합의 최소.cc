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
	int st = 0;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	ll ans = v[n - 1];
	for (int i = n-2; i>=0; i--)
	{
		if (v[i] > v[i + 1])
		{
			v[i] = v[i + 1];
		}
		ans += v[i];
	}

	cout << ans;
	
	return 0;
}