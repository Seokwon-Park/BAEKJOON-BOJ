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

	int amx, bmx, cmx;
	int a, b, c;
	cin >> amx >> a >> bmx >> b >> cmx >> c;

	for (int i = 0; i < 100; i++)
	{
		if (i%3 == 0)
		{
			b += a;
			if (b > bmx)
			{
				a = b - bmx;
				b = bmx;
			}
			else
				a = 0;
		}
		else if (i % 3 == 1)
		{
			c += b;
			if (c > cmx)
			{
				b = c - cmx;
				c = cmx;
			}
			else
				b = 0;
		}
		else
		{
			a += c;
			if (a > amx)
			{
				c = a - amx;
				a = amx;
			}
			else
				c = 0;
		}
	}
	cout << a << '\n' << b << '\n' << c;
	

	return 0;
}