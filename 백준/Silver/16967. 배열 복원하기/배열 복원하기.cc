#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int b[605][605];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, w, x, y;
	cin >> h >> w >> x >> y;

	for (int i = 0; i < h + x; i++)
	{
		for (int j = 0; j < w + y; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = x; i < h; i++)
	{
		for (int j = y; j < w; j++)
		{
			b[i][j] -= b[i - x][j - y];
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << b[i][j] << ' ';
		}
		cout << '\n';
	}

	

	return 0;
}