#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using hashmap = unordered_map<key, value>;

int calc(int w, int h, int tw, int th)
{
	int fold = 0;
	while (w >= tw * 2)
	{
		if (w % 2)
		{
			w = w / 2 + 1;
		}
		else
		{
			w /= 2;
		}
		fold++;
	}

	while (h >= th * 2)
	{
		if (h % 2)
		{
			h = h / 2 + 1;
		}
		else
		{
			h /= 2;
		}
		fold++;
	}

	if (w != tw) fold++;
	if (h != th) fold++;

	return fold;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int w, h, a;
	cin >> w >> h >> a;
	if (w > h) swap(w, h);

	int ans = INF;
	for (int i = 1; i * i <= a; i++)
	{
		if (a % i == 0)
		{
			int nw = i;
			int nh = a / i;

			if (nw <= w && nh <= h)
			{
				ans = min(ans, calc(w, h, nw, nh));
			}

			if (nw <= h && nh <= w)
			{
				ans = min(ans, calc(w, h, nh, nw));
			}
		}
	}
	cout << (ans == INF ? -1 : ans);

	return 0;
}