#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

bool isused[11][11];
int b[11][11];
int n;
int res;

void bloom(int x, int y)
{
	isused[y][x] = true;
	isused[y + 1][x] = true;
	isused[y][x + 1] = true;
	isused[y - 1][x] = true;
	isused[y][x - 1] = true;
	res += b[y][x];
	res += b[y + 1][x];
	res += b[y][x + 1];
	res += b[y - 1][x];
	res += b[y][x - 1];
}

void fall(int x, int y)
{
	isused[y][x] = false;
	isused[y + 1][x] = false;
	isused[y][x + 1] = false;
	isused[y - 1][x] = false;
	isused[y][x - 1] = false;
	res -= b[y][x];
	res -= b[y + 1][x];
	res -= b[y][x + 1];
	res -= b[y - 1][x];
	res -= b[y][x - 1];
}

bool isBound(int x, int y)
{
	if (x == 0 || y == 0 || x == n-1 || y == n-1)return true;
	return false;
}

bool isOverlap(int x, int y)
{
	if (isused[y][x] || isused[y+1][x] || isused[y][x+1] || isused[y-1][x] || isused[y][x-1])return true;
	return false;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}

	int ans = INT_MAX;
	for (int i = 0; i < n * n; i++)
	{
		int ix = i % n;
		int iy = i / n;
		if (isBound(ix, iy))continue;
		bloom(ix, iy);
		for (int j = i + 1; j < n * n; j++)
		{
			int jx = j % n;
			int jy = j / n;
			if (isBound(jx, jy) || isOverlap(jx,jy)) continue;
			bloom(jx, jy);
			for (int k = j + 1; k < n * n; k++)
			{
				int kx = k % n;
				int ky = k / n;
				if (isBound(kx, ky) || isOverlap(kx,ky)) continue;
				bloom(kx, ky);
				ans = min(res, ans);
				fall(kx, ky);
			}
			fall(jx, jy);
		}
		fall(ix, iy);
	}
	cout << ans;


	return 0;
}