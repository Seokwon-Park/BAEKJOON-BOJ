#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dmax[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int y, m;
		cin >> y >> m;
		if (m - 1 == 0)
		{
			y -= 1;
			cout << y << " 12 31\n";
		}
		else if(m-1 == 2)
		{
			if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
			{
				cout << y << " 2 29\n";
			}
			else
			{
				cout << y << ' ' << m - 1 << ' ' << dmax[m-1] << '\n';
			}
		}
		else
		{
			cout << y << ' ' << m - 1 << ' ' << dmax[m-1] << '\n';
		}

	}

	return 0;
}