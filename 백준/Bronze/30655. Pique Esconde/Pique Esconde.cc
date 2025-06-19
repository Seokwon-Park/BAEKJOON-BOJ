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

	int n, m;
	while (true)
	{
		cin >> n >> m;
		vector<bool> chk(n + 1, false);
		if (n == 0 && m == 0) break;
		chk[m] = true;
		for (int i = 0; i < n - 2; i++)
		{
			int x;
			cin >> x;
			chk[x] = true;
		}

		for (int i = 1; i <= n; i++)
		{
			if (!chk[i])
			{
				cout << i << '\n';
				break;
			}

		}
	}

	return 0;
}