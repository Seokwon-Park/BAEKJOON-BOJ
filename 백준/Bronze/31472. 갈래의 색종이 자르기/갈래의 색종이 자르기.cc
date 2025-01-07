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
	
	int w;
	cin >> w;
	for (int i = 1; i*i < w; i++)
	{
		if (w % i == 0)
		{
			int x = w / i;
			if (i * 2 == x)
			{
				cout << x * 4;
				return 0;
			}
		}
	}

	return 0;
}