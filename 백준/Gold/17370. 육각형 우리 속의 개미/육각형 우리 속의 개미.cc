#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int v[105][105];
int ans = 0;
int n;
int dxeven[3] = { 1,-1,0 };
int dyeven[3] = { 0,0,1 };

int dxodd[3] = { 1,-1,0 };
int dyodd[3] = { 0,0,-1 };


void dfs(int x, int y, int rot, int px, int py)
{
	if (v[x][y])
	{
		if (rot == n)
			ans++;
		return;
	}
	if (rot == n) return;

	v[x][y] = true;
	for (int i = 0; i < 3; i++)
	{
		int tx, ty;
		if ((x + y) % 2 == 0)
		{
			tx = x + dxeven[i];
			ty = y + dyeven[i];
		}
		else
		{
			tx = x + dxodd[i];
			ty = y + dyodd[i];
		}
		if (tx == px && ty == py) continue;
		dfs(tx, ty, rot + 1, x, y);
	}
	v[x][y] = false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	v[50][50] = true;
	dfs(50, 51, 0, 50, 50);
	cout << ans;

	return 0;
}
