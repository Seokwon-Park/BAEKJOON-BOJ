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
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans += i * i;
		}
		cout << ans << '\n';
	}


	return 0;
}