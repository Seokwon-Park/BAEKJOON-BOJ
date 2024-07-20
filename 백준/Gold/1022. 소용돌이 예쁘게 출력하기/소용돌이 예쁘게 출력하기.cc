#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int r1, c1, r2, c2;
int b[50][50];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r1 >> c1 >> r2 >> c2;

	int mx = -1;
	for (int r = r1; r <= r2; r++)
	{
		for (int c = c1; c <= c2; c++)
		{
			int nr = r - r1;
			int nc = c - c1;
			if (r < 0)
			{
				if (abs(r) >= abs(c))
				{
					b[nr][nc] = (abs(r) * 2) * (abs(r) * 2) + 1 - abs(r - c);
				}
				if (abs(r) < abs(c))
				{
					if (c < 0)
					{
						b[nr][nc] = (abs(c) * 2) * (abs(c) * 2) + 1 + abs(r - c);
					}
					else if (c > 0)
					{
						b[nr][nc] = (abs(c) * 2) * (abs(c) * 2) + 1 - (abs(c) * 2) - abs(abs(r) - abs(c));
					}
				}
			}
			else
			{
				if (abs(r) >= abs(c))
				{
					b[nr][nc] = (abs(r) * 2 + 1) * (abs(r) * 2 + 1) - abs(r - c);
				}
				if (abs(r) < abs(c))
				{
					if (c < 0)
					{
						b[nr][nc] = (abs(c) * 2) * (abs(c) * 2) + 1 + abs(r - c);
					}
					else
					{
						b[nr][nc] = (abs(c) * 2) * (abs(c) * 2) + 1 - (abs(c) * 2) - abs(r+ c);
					}
				}
			}
			mx = max(mx, b[nr][nc]);
		}
	}

	int sz = 0;
	while (mx)
	{
		mx /= 10;
		sz++;
	}

	for (int r = 0; r <= r2 - r1; r++)
	{
		for (int c = 0; c <= c2 - c1; c++)
		{
			cout << setw(sz) << setfill(' ') << b[r][c] << ' ';
		}
		cout << '\n';
	}

	return 0;
}