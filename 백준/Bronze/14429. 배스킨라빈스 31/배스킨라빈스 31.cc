#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

bool b[505][505];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int ans = INF;
	int ix = 0;
	for (int i = 1; i <= n; i++)
	{
		int j, m;
		cin >> j >> m;
		int r = (j - 1) % (m + 1);
		int k = (j - r) / (m + 1);
		if (ans > (k + 1) * 2)
		{
			ix = i;
			ans = (k + 1) * 2;
		}
	}
	cout << ix << ' ' << ans;

	return 0;
}

