#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using hashmap = unordered_map<key, value>;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int n, m;
int b[1005][1005];
int v1[1005][1005];
int v2[1005][1005];

void bfs(pii virus1, pii virus2)
{
	queue<pii>q1, q2;
	q1.push(virus1);
	q2.push(virus2);
	v1[virus1.second][virus1.first] = 1;
	v2[virus2.second][virus2.first] = 1;
	int t = 2;
	while (!q1.empty() || !q2.empty())
	{
		int q1s = q1.size();
		int q2s = q2.size();
		for (int i = 0; i < q1s; i++)
		{
			auto [x, y] = q1.front();
			q1.pop();
			if (b[y][x] == 3) continue;
			for (int j = 0; j < 4; j++)
			{
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx < 0 || ty < 0 || tx >= m || ty >= n || v1[ty][tx] || b[ty][tx] == -1 || b[ty][tx] == 2)continue;
				b[ty][tx] = 1;
				v1[ty][tx] = t;
				q1.push({ tx,ty });
				
			}
		}

		for (int i = 0; i < q2s; i++)
		{
			auto [x, y] = q2.front();
			q2.pop();
			for (int j = 0; j < 4; j++)
			{
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx < 0 || ty < 0 || tx >= m || ty >= n || v2[ty][tx] || b[ty][tx] == -1)continue;
				if (b[ty][tx] == 1)
				{
					if (v1[ty][tx] == t)
					{
						b[ty][tx] = 3;
						v2[ty][tx] = t;
					}
				}
				else
				{
					b[ty][tx] = 2;
					v2[ty][tx] = t;
					q2.push({ tx,ty });
				}
			}
		}
		t++;
		
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	pii virus1, virus2;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 1)
				virus1 = { j,i };
			if (b[i][j] == 2)
				virus2 = { j,i };
		}
	}

	bfs(virus1, virus2);


	vector<int> ans(3);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (b[i][j] <= 0) continue;
			ans[b[i][j] - 1]++; 
		}
	}

	for (auto i : ans)
	{
		cout << i << ' ';
	}

	return 0;
}