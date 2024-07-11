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

	int p, n;
	cin >> p >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (p < 200)
		{
			p += v[i];
			ans++;
		}
		else
		{
			break;
		}
	}
	cout << ans;

	return 0;
}