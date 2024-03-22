#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll x, y, w, s;
	cin >> x >> y >> w >> s;
	if (x > y)
		swap(x, y);
	//min is x;
	if (w * 2 > s)
	{
		ll res = x * s;
		if (w > s)
		{
			if ((y - x) % 2 == 0)
			{
				res += (y - x) * s;
			}
			else
			{
				res += (y - x - 1) *s + w;
			}
		}
		else
		{
			res += (y - x) * w;
		}
		cout << res;
	}
	else
	{
		cout << x * 2 * w + (y - x) * w;
	}

	return 0;
}