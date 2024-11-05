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

	int s, t;
	cin >> s >> t;

	ll tres = 0;
	for (int i = 1; i <= t; i++)
	{
		if (i % 2 == 1)
		{
			tres += -1 * t / i;
		}
		else
		{
			tres += 1 * t / i;
		}
	}

	ll sres = 0;
	for (int i = 1; i <= s-1; i++)
	{
		if (i % 2 == 1)
		{
			sres += -1 * (s-1) / i;
		}
		else
		{
			sres += 1 * (s-1) / i;
		}
	}

	cout << tres - sres;
	
	return 0;
}
