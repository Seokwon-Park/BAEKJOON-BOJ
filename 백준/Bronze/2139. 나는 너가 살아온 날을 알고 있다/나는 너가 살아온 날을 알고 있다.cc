
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

int prefd[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

bool isLeap(int y)
{
	if (y % 400 == 0) return true;
	else if (y % 100 == 0) return false;
	else if (y % 4 == 0) return true;
	else return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int y, m, d;
	while (cin >> d >> m >> y)
	{
		if (y == 0 && m == 0 && d == 0) break;
		int res = prefd[m] + d;
		if (isLeap(y) && m >2)
		{
			res++;
		}
		cout << res << '\n';
	}

	return 0;
}