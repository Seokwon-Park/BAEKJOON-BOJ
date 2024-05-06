#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};
int b[55][55];
bool wasCloud[55][55];
int n, m;

int magic(int x, int y)
{
	int ret = 0;
	for (int i = 1; i < 8; i += 2)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx >= n || ty >= n) continue;
		if (b[ty][tx] > 0)
			ret++;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}

	queue<pii> qc;
	qc.push({ n-1,0 });
	qc.push({ n-1,1 });
	qc.push({ n-2,0 });
	qc.push({ n-2,1 });
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int d, s;
		cin >> d >> s;
		d--; //  1->0 indexed
		int qs = qc.size();
		vector<pii> tmp;
		for (int j = 0; j < qs; j++)
		{
			auto [ty, tx] = qc.front();
			qc.pop();
			tx = tx + dx[d] * s;
			ty = ty + dy[d] * s;
			while (tx < 0) tx += n;
			while (ty < 0) ty += n;
			tx %= n;
			ty %= n;
			wasCloud[ty][tx] = true;
			b[ty][tx]++;
			tmp.push_back({ ty, tx });
		}

		for (auto [y, x] : tmp)
		{
			b[y][x] += magic(x, y);
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (b[i][j] >= 2 && !wasCloud[i][j])
				{
					qc.push({ i,j });
					b[i][j] -= 2;
				}
				if (wasCloud[i][j])
					wasCloud[i][j] = false;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ans += b[i][j];
		}
	}

	cout << ans;

	return 0;
}
