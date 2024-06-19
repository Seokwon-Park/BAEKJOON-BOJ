#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int w, n;
		cin >> w >> n;
		int moved = 0;
		int cur = 0;
		int curw = 0;
		for (int i = 0; i < n; i++)
		{
			int x, ww;
			cin >> x >> ww;
			if (curw + ww < w)
			{
				cur = x;
				curw += ww;
			}
			else if (curw + ww == w)
			{
				moved += x * 2;
				curw = 0;
			}
			else
			{
				moved += x * 2;
				cur = x;
				curw = ww;
			}
		}
		if (curw != 0)
		{
			moved += cur * 2;
		}
		cout << moved << '\n';
	}


	return 0;
}