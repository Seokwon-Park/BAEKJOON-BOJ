#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int n;
double dir[4];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int b[30][30];
bool v[30][30];


double dfs(int x, int y, int k, double rate)
{
	if (k == n)
	{
		return rate;
	}
	double res = 0;
	for (int i = 0; i < 4; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (dir[i] == 0) continue;
		if (v[ty][tx])continue;
		v[ty][tx] = true;
		res += dfs(tx, ty, k + 1, rate * dir[i] / 100.0);
		v[ty][tx] = false;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < 4; i++)
	{
		cin >> dir[i];
	}
	
	v[14][14] = true;
	cout << fixed;
	cout.precision(9);
	cout << dfs(14,14, 0, 1.0);

	return 0;
}