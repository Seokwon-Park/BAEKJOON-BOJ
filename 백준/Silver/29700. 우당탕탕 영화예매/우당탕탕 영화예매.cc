#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int cont = 0;
		for (auto c : s)
		{
			if (c == '0')
			{
				cont++;
			}
			else
			{
				if (k <= cont)
				{
					ans += cont - k + 1;
				}
				cont = 0;
			}
		}
		if (k <= cont)
		{
			ans += cont - k + 1;
		}
	}
	cout << ans;


	return 0;
}



