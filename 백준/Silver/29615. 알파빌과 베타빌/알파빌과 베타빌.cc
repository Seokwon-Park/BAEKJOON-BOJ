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

	int n, m;
	cin >> n >> m;
	vector<int> v(n+5);
	for(int i = 0; i<n ;i++)
	{
		int k;
		cin >> k;
		v[k] = i;
	}

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		if (v[k] >= m)
			ans++;
	}
	cout << ans;

	return 0;
}