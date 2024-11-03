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
	
	int x, n;
	cin >> x >> n;
	if (n == 1)
	{
		if (-x > 0)
		{
			cout << "INFINITE";
		}
		else
		{
			cout << 0;
		}
	}
	else if (n % 2 == 1)
	{
		cout << "ERROR";
	}
	else
	{
		if (n == 0)
		{
			if (x > 0)
			{
				cout << "INFINITE";
			}
			else
			{
				cout << 0;
			}
		}
		else
		{
			int minus = n / 2;
			int res = 0;
			x -= minus;
			while (x > 0)
			{
				res++;
				x -= minus;
			}
			cout << res;
		}
	}

	
	return 0;
}