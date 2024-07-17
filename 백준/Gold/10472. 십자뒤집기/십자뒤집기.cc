#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;


int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

bool v[1 << 10];

int flip(int rc, int s)
{
	int r = rc / 3;
	int c = rc % 3;
	s ^= 1 << rc;
	for (int i = 0; i < 4; i++)
	{
		int tx = c + dx[i];
		int ty = r + dy[i];
		if (tx < 0 || ty < 0 || tx >= 3 || ty >= 3) continue;
		s ^= 1 << ty * 3 + tx;
	}
	return s;
}

int bfs(int target)
{
	queue<int> q;
	q.push(0);
	v[0] = 1;
	int clicked = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int j = 0; j < qs; j++)
		{
			int cur = q.front();
			q.pop();
			for (int i = 0; i < 9; i++)
			{
				int nxt = flip(i, cur);
				if (v[nxt]) continue;
				if (nxt == target)
				{
					return clicked + 1;
				}
				q.push(nxt);
				v[nxt] = true;
			}
		}
		clicked++;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		fill(v, v + 1024, false);
		int target = 0;
		for (int i = 0; i < 3; i++)
		{
			for(int j = 0; j<3; j++)
			{
				char c;
				cin >> c;
				if (c == '*')
					target += 1 << (i * 3 + j);
			}
		}
		cout << bfs(target) << '\n';
		
	}
	
	return 0;
}