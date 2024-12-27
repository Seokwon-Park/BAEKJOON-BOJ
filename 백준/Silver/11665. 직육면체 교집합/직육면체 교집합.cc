#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

vector<pair<int, double>> adj[4];

void dfs()
{

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int x1 = 0;
	int y1 = 0;
	int z1 = 0;
	int x2 = INF;
	int y2 = INF;
	int z2 = INF;
	for (int i = 0; i < n; i++)
	{
		int x, y, z, xx, yy, zz;
		cin >> x >> y >> z >> xx >> yy >> zz;
		x1 = max(x1, x);
		y1 = max(y1, y);
		z1 = max(z1, z);
		x2 = min(x2, xx);
		y2 = min(y2, yy);
		z2 = min(z2, zz);
	}

	cout << max(0, x2 - x1) * max(0, y2 - y1) * max(0, z2 - z1);



	return 0;
}



