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
		int a, b;
		cin >> a >> b;

		while (a != b)
		{
			if (a > b)
			{
				a >>= 1;
			}
			else if (a < b)
			{
				b >>= 1;
			}
		}
		cout << a * 10 << '\n';
	}

	return 0;
}