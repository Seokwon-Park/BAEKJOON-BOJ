#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int w, h;
int types[55][55];
int b[55][55];
int n;
vector<pii> blocks;
vector<pii> lamps;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

bool chk[55][55];


bool bfs()
{
	queue<pii> q;
	for (auto [x, y] : blocks)
	{
		b[y][x] = 15;
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || ty < 0 || tx >= w || ty >= h || chk[ty][tx]) continue;
			if (types[ty][tx] == 1)
			{
				b[ty][tx] = 15;
				q.push({ tx,ty });
			}
			else if (types[ty][tx] == 2)
			{
				b[ty][tx] = 15;
			}
		}
	}
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			auto [x, y] = q.front();
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx < 0 || ty < 0 || tx >= w || ty >= h || b[ty][tx] >= b[y][x]) continue;
				b[ty][tx] = b[y][x] - 1;
				q.push({ tx,ty });
			}
		}
	}

	//for (int i = 0; i < h; i++)
	//{
	//	for (int j = 0; j < w; j++)
	//	{
	//		cout << b[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	bool isOfflamp = false;
	for (auto [x, y] : lamps)
	{
		if (b[y][x] == 0)
		{
			isOfflamp = true;
			break;
		}
	}
	return !isOfflamp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> w >> h;
	cin >> n;
	for(int i = 0; i< n;i++)
	{
		string s;
		int x, y;
		cin >> s >> x >> y;
		if (s == "redstone_block")
		{
			blocks.push_back({ x, y });
		}
		else if(s == "redstone_dust")
		{
			types[y][x] = 1;
		}
		else
		{
			types[y][x] = 2;
			lamps.push_back({ x,y });
		}
	}

	cout << (bfs() ? "success" : "failed");
	

	
	return 0;
}