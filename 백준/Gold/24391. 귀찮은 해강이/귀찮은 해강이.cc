#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

vector<int> p(100005, -1);

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void uni(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return;
	if (p[a] == p[b]) p[a]--;
	if (p[a] < p[b]) p[b] = a;
	else p[a] = b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		uni(a, b);
	}

	int cur;
	cin >> cur;
	int ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int nxt;
		cin >> nxt;
		if (find(cur) != find(nxt))
		{
			ans++;
		}
		cur = nxt;
	}
	cout << ans;

	return 0;
}