#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int r, c;
int rg, rp, cg, cp;
char b[105][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c;
	cin >> rg >> cg >> rp >> cp;

	int lux = INF;
	int luy = INF;
	int rdx = -1;
	int rdy = -1;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 'P')
			{
				lux = min(lux, j);
				luy = min(luy, i);
				rdx = max(rdx, j);
				rdy = max(rdy, i);
			}
		}
	}

	int h = rdy - luy + 1;
	int w = rdx - lux + 1;
	if (h != rp || w != cp)
	{
		cout << 1;
		return 0;
	}

	for (int i = luy; i < luy + rp; i++)
	{
		for (int j = lux; j < lux + cp; j++)
		{
			if (b[i][j] == 'G')
			{
				cout << 1;
				return 0;
			}
		}
	}

	cout << 0;

	return 0;
}

