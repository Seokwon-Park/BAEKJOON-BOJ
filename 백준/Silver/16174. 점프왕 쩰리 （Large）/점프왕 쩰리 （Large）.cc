#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int b[64][64];
int v[64][64];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}

	queue<pii> q;
	q.push({ 0,0 });
	v[0][0] = 1;
	int dx[2] = { 1,0 };
	int dy[2] = { 0,1 };
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 2; i++)
		{
			int tx = x + dx[i]*b[y][x];
			int ty = y + dy[i] * b[y][x];
			if (tx >= n || ty >= n || v[ty][tx]) continue;
			if (b[ty][tx] == -1)
			{
				cout << "HaruHaru";
				return 0;
			}
			q.push({ tx,ty });
			v[ty][tx] = true;
		}
	}

	cout << "Hing";

	return 0;
}