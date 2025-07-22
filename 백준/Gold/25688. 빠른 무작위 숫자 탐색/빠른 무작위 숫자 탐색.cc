#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

int b[5][5];
bool v[5][5];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int bfs(int r, int c, int nxtr, int nxtc)
{
	queue<pii> q;
	q.push({ r,c });
	int dist = 0;
	v[r][c] = true;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			auto [cr, cc] = q.front();
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int tr = cr + dy[j];
				int tc = cc + dx[j];
				if (v[tr][tc] || tr < 0 || tc < 0 || tr >= 5 || tc >= 5|| b[tr][tc] == -1) continue;
				if (tr == nxtr && tc == nxtc)
				{
					return dist + 1;
				}
				v[tr][tc] = true;
				q.push({ tr,tc });
			}
		}
		dist++;
	}
	return -1;

}

void resetv()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			v[i][j] = false;
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<pii> numpos(7);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> b[i][j];
			if (b[i][j] != -1 && b[i][j] != 0)
			{
				numpos[b[i][j]] = { i,j };
			}
			v[i][j] = false;
		}
	}


	int r, c;
	cin >> r >> c;
	int ans = INF;
	vector<int> order = { 1,2,3,4,5,6 };
	do
	{
		int cr = r;
		int cc = c;
		bool isSucceed = true;
		int moved = 0;
		for (int i = 0; i < order.size(); i++)
		{
			resetv();
			auto [tr, tc] = numpos[order[i]];
			int res = bfs(cr, cc, tr, tc);
			if (res < 0)
			{
				// 어차피 못가는 곳이 있으면 무슨 경우던 완료 못함
				cout << -1;
				return 0;
			}
			moved += res;
			cr = tr;
			cc = tc;
		}
		if (isSucceed)
		{
			ans = min(ans, moved);
		}
	} while (next_permutation(order.begin(), order.end()));

	cout << ans;

	return 0;
}
 