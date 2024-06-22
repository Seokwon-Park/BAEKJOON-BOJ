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

	while (1)
	{
		int n;
		cin >> n;
		if (!n) break;
		int ans = n;
		while ((ans/ 10) != 0)
		{
			int res = 0;
			int tmp = ans;
			while (tmp)
			{
				res += tmp % 10;
				tmp /= 10;
			}
			ans = res;
		}
		cout << ans << '\n';
	}
	
	return 0;
}