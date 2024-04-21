#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

char b[255][255];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int n;
int hx, hy;
int fx, fy;

void bfs(vector<pii>& store, map<int, map<int, bool>>& v)
{
	queue<pii> q;

	q.push({ hx,hy });
	v[hx][hy] = true;
	while (!q.empty())
	{
		auto [cx, cy] = q.front();
		q.pop();
		for (int i = 0; i < n; i++)
		{
			auto [tx, ty] = store[i];
			if (v[tx][ty]) continue;
			if (abs(tx - cx) + abs(ty - cy) > 1000)continue;
			if (abs(fx - tx) + abs(fy - ty) <= 1000)
			{
				cout << "happy";
				return;
			}
			q.push({tx,ty});
			v[tx][ty] = true;
		}
	}
	cout << "sad";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n;
		cin >> hx >> hy;
		vector<pii> store;
		map<int, map<int, bool>> v;
		for (int i = 0; i < n; i++)
		{
			int xx, yy;
			cin >> xx >> yy;
			store.push_back({ xx,yy });
		}
		cin >> fx >> fy;
		if (abs(fx - hx) + abs(fy - hy) <= 1000)
		{
			cout << "happy";
		}
		else
		{
			bfs(store, v);
		}
		cout << '\n';
	}

	return 0;
}