#include <bits/stdc++.h>

using namespace std;

int p[1000001];
//int board[1005][1005];
//bool ismst[1005];

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void yunion(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v) return;
	//union by rank
	if (p[u] < p[v]) // u의 parent가 더 높은 위치인 경우
	{
		p[v] = u;
	}
	else
	{
		p[u] = v;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) p[i] = -1;

	for (int i = 0; i < m; i++)
	{
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 0)
		{
			yunion(a, b);
		}
		else
		{
			cout << (find(a) == find(b) ? "YES" : "NO") << '\n';
		}
	}
	//fill(p, p + 1005, -1);
	

	return 0;
}