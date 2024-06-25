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

	int tc;
	cin >> tc;
	while (tc--)
	{
		int k;
		cin >> k;

		int ans = 0;
		for (int i = 0; i < k; i++)
		{
			ans = ans * 2 + 1;
		}
		cout << ans << '\n';
	}

	return 0;
}