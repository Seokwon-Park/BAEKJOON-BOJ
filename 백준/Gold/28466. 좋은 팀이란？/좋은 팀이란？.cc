#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int a[10][10];
int b[12][12];
vector<int> cur;
vector<pii> v;
priority_queue<int> c[10][12];
bool isUsed[1000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			cin >> b[i][j];
		}
	}

	int i = 0;
	int j = 0;
	int cnt = 60;
	while (cnt--)
	{
		v.push_back({ i,j });
		i = (i + 1) % 10;
		j = (j + 1) % 12;
	}

	for (int i = 0; i < n; i++)
	{
		int x;
		string s;
		cin >> x >> s;
		int a = s[0] - '0';
		int b = s[1] - 'A';
		c[a][b].push(x);
	}
	int ans = 0;
	for (int i = 0; i < 60; i++)
	{
		if (c[v[i].first][v[i].second].empty()) continue;
		int x = c[v[i].first][v[i].second].top();
		c[v[i].first][v[i].second].pop();
		for (int j = 0; j < 60; j++)
		{
			if (c[v[j].first][v[j].second].empty()) continue;
			int y = c[v[j].first][v[j].second].top();
			c[v[j].first][v[j].second].pop();
			for (int k = 0; k < 60; k++)
			{
				if (c[v[k].first][v[k].second].empty()) continue;
				int z = c[v[k].first][v[k].second].top();
				c[v[k].first][v[k].second].pop();
				int res = x + y + z;
				res += a[v[i].first][v[j].first] + a[v[j].first][v[k].first] + a[v[k].first][v[i].first];
				res += b[v[i].second][v[j].second] + b[v[j].second][v[k].second] + b[v[k].second][v[i].second];
				ans = max(ans, res);
				c[v[k].first][v[k].second].push(z);
			}
			c[v[j].first][v[j].second].push(y);
		}
		c[v[i].first][v[i].second].push(x);
	}

	cout << ans;

	return 0;
}

