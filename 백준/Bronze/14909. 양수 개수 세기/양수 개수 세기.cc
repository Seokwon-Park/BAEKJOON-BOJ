#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

bool dp[1000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	int ans = 0;
	while (cin >> n)
	{
		if (n > 0)
			ans++;
	}

	cout << ans;

	return 0;
}