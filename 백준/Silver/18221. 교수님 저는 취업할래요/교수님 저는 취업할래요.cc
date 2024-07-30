#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int b[1005][1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int sx, sy;
	int px, py;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 5)
			{
				px = j;
				py = i;
			}
			if (b[i][j] == 2)
			{
				sx = j;
				sy = i;
			}
		}
	}

	int dist = (px - sx) * (px - sx) + (py - sy) * (py - sy);
	if (dist < 25.0)
	{
		cout << 0;
		return 0;
	}
	if (sx > px)swap(sx, px);
	if (sy > py)swap(sy, py);
	int students = 0;
	for (int i = sy; i <= py; i++)
	{
		for (int j = sx; j <= px; j++)
		{
			if (b[i][j] == 1)
			{
				students++;
			}
		}
	}
	if (students < 3)
	{
		cout << 0;
		return 0;
	}
	cout << 1;

	return 0;
}