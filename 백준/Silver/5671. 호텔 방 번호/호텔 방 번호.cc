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
	
	int n, m;
	while (cin >> n >> m)
	{
		int ans = 0;
		for (int i = n; i <= m; i++)
		{
			vector<bool> v(10, false);
			int tmp = i;
			bool isLucky = true;
			while (tmp)
			{
				int mod = tmp % 10;
				if (!v[mod])
					v[mod] = true;
				else
				{
					isLucky = false;
					break;
				}
				tmp /= 10;
			}
			if (isLucky)
				ans++;
		}
		cout << ans << '\n';
	}
	
	return 0;
}