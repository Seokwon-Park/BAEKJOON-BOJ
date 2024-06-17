#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
		
	int n, x;
	cin >> n >> x;
	int ans = -1;
	for (int i = 0; i < n; i++)
	{
		int s, t;
		cin >> s >> t;
		if (s + t <= x)
		{
			ans = max(ans, s);
		}
	}
	cout << ans;

	return 0;
}