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
		int a, b, c, p;
		cin >> a >> b >> c >> p;

		if (a % p == 0 && b % p == 0)
		{
			cout << 1;
		}
		else if (b % p == 0 && c % p == 0)
		{
			cout << 1;
		}
		else if (c % p == 0 && a % p == 0)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
		cout << '\n';
	}

	return 0;
}
