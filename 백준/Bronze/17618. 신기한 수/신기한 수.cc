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
	for (int i = 1; i <= n; i++)
	{
		int tmp = i;
		int div = 0;
		while (tmp)
		{
			div += tmp % 10;
			tmp /= 10;
		}
		if (i % div == 0)
			ans++;
	}
	cout << ans;

	return 0;
}