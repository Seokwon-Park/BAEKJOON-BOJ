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
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int ans = 0;
	int	streak = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] > 0)
		{
			streak++;
		}
		else
		{
			ans = max(ans, streak);
			streak = 0;
		}
	}
	ans = max(ans, streak);
	cout << ans;

	
	return 0;
}
