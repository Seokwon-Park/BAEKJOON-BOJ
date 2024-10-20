#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	char c;
	cin >> c;
	string s = "ILOVEYONSEI";

	int cur = c - 'A';
	int ans = 0;
	for (auto c : s)
	{
		int ix = c - 'A';
		if (ix >= cur)
		{
			ans += ix - cur;
		}
		else
		{
			ans += cur - ix;
		}
		cur = ix;
	}

	cout << ans;
	return 0;
}