
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

vector<int> p(1000005, -1);
char b[1005][1005];

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void union_(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (p[a] > p[b]) p[b] = a;
	else p[a] = b;
}

pii calcDir(int x, int y, char dir)
{
	if (dir == 'U')
		return { x, y - 1 };
	else if (dir == 'D')
		return { x, y + 1 };
	else if (dir == 'L')
		return { x - 1, y };
	else
		return { x + 1, y };
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			auto [tx, ty] = calcDir(j, i, b[i][j]);
			int cur = i * m + j;
			int nxt = ty * m + tx;
			union_(cur, nxt);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (p[i * m + j] == -1)
				ans++;
		}
	}
	cout << ans;

	return 0;
}