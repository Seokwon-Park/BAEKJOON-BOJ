#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int n;
int fr[25];
int ans;


void func(int k, int res, int used)
{
	if (k == n)
	{
		if (res == (1 << n) - 1)
		{
			ans = min(ans,used);
		}
		return;
	}

	func(k + 1, res | fr[k], used + 1);
	func(k + 1, res, used);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		ans = INF;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int k;
			cin >> k;
			fr[i-1] = 1 << (i - 1);
			for (int j = 0; j < k; j++)
			{
				int f;
				cin >> f;
				fr[i-1] += 1 << (f-1);
			}
		}
		func(0, 0, 0);
		cout << ans << '\n';
	}



	return 0;
}