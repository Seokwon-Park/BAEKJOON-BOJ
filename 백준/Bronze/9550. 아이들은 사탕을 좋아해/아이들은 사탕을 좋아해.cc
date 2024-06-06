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

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, k;
		cin >> n >> k;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int m;
			cin >> m;
			ans += m / k;
		}
		cout << ans << '\n';
	}

	return 0;
}
