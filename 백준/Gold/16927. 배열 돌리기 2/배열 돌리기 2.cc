#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int b[305][305];

void rotate(int x, int y, int w, int h, int rot)
{
	if (w <= 1 || h <= 1)return;

	int st = b[y][x];
	vector<int> tmp;
	for (int c = x; c < x + w - 1; c++)
		tmp.push_back(b[y][c]);
	for (int r = y; r < y + h - 1; r++)
		tmp.push_back(b[r][x + w - 1]);
	for (int c = x + w - 1; c > x; c--)
		tmp.push_back(b[y + h - 1][c]);
	for (int r = y + h - 1; r > y; r--)
		tmp.push_back(b[r][x]);
	vector<int> res(tmp.size());

	for (int i = 0; i < tmp.size(); i++)
	{
		res[i] = tmp[(i + rot) % tmp.size()];
	}

	int cnt = 0;
	for (int c = x; c < x + w - 1; c++)
		b[y][c] = res[cnt++];
	for (int r = y; r < y + h - 1; r++)
		b[r][x + w - 1] = res[cnt++];
	for (int c = x + w - 1; c > x; c--)
		b[y + h - 1][c] = res[cnt++];
	for (int r = y + h - 1; r > y; r--)
		b[r][x]=res[cnt++];

	rotate(x + 1, y + 1, w - 2, h - 2, rot);


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}

	rotate(0, 0, m, n, r);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << b[i][j] << ' ';
		}
		cout << '\n';
	}


	return 0;
}
