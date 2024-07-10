#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l, r;
	cin >> l >> r;

	int cur = 2;
	int prev = l;
	int ans = 0;
	while (1)
	{
		int nxt = prev * r / 100;
		if (nxt > 5)
			ans += nxt * cur;
		else
			break;
		cur *= 2;
		prev = nxt;
	}

	cout << ans;

	return 0;
}
