#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

bool used[10005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		for (int j = x; j <= n; j+=y)
		{
			used[j] = true;
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			ans++;
		}
	}
	cout << ans;


	return 0;
}
