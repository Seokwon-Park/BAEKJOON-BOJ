#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int x = 0;
	int y = 0;

	int moved = 0;
	int turned = 0;
	int dir = 0;
	int nxt = 1;

	while (n--)
	{
		x += dx[dir];
		y += dy[dir];
		moved++;
		if (moved == nxt)
		{
			moved = 0;
			turned++;
			dir = (dir + 1) % 4;
			if (turned == 2)
			{
				turned = 0;
				nxt++;
			}
		}
	}
	cout << x << ' ' << y;

	return 0;
}