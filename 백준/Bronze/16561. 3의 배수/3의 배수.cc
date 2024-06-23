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

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 3; i <= n; i+=3)
	{
		for (int j = 3; j <= n; j+=3)
		{
			if (n - i - j > 0)
				ans++;
			else
				break;
		}
	}
	cout << ans;

	return 0;
}