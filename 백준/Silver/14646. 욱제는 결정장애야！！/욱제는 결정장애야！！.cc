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

	int n;
	cin >> n;
	vector<int> v(n + 1);
	int sticker = 0;
	int ans = 0;
	for (int i = 0; i < 2*n; i++)
	{
		int m;
		cin >> m;
		if (v[m] == 0)
		{
			v[m] = 1;
			sticker++;
		}
		else
		{
			v[m] = 0;
			sticker--;
		}
		ans = max(ans, sticker);
	}
	cout << ans;

	return 0;
}