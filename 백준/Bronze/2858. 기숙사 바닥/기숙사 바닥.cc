#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int r, b;
	cin >> r >> b;
	// l + w = 2 + r/2
	// lw = r + b;

	for (int l = 3; l * l <= r + b; l++)
	{
		if ((r + b) % l == 0)
		{
			int w = (r + b) / l;
			if ((l * 2 + w * 2 - 4) == r)
			{
				cout << w << ' ' << l;
				return 0;
			}
		}
	}



	return 0;
}
