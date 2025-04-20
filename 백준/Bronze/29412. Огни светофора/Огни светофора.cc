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

	int g, gb, y, r, ry;
	cin >> g >> gb >> y >> r >> ry;
	int t;
	cin >> t;
	
	//r,y,g
	int a = 0;
	int b = 0;
	int c = 0;
	while (1)
	{
		int x = min(t, g);
		c += x;
		t -= x;
		if (t <= 0) break;
		x = min(t, gb);
		c += x / 2;
		t -= x;
		if (t <= 0) break;
		x = min(t, y);
		b += x;
		t -= x;
		if (t <= 0) break;
		x = min(t, r);
		a += x;
		t -= x;
		if (t <= 0) break;
		x = min(t, ry);
		a += x;
		b += x;
		t -= x;
		if (t <= 0) break;
	}

	cout << a << ' ' << b << ' ' << c;

	return 0;
}