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

	int tc;
	cin >> tc;

	while (tc--)
	{
		int m;
		char n;
		cin >> m >> n;
		for (int i = 0; i < m; i++)
		{
			if (n == 'C')
			{
				char k;
				cin >> k;
				cout << k - 'A' + 1 << ' ';
			}
			else
			{
				int k;
				cin >> k;
				cout << (char)('A' + (k - 1)) << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}
