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

	int m, seed, x1, x2;
	cin >> m >> seed >> x1 >> x2;
	
	for (int a = 0; a < m; a++)
	{
		for (int c = 0; c < m; c++)
		{
			if ((a * seed + c) % m == x1 && (a * x1 + c) % m == x2)
			{
				cout << a << ' ' << c;
				return 0;
			}
		}
	}


	return 0;
}