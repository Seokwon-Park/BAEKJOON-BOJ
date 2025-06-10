#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int deg[3005];
vector<int> p(3005, -1);

int find(int x)
{
	if (p[x] == -1) return x;
	else return p[x] = find(p[x]);
}

void doUnion(int a, int b)
{
	int aa = find(a);
	int bb = find(b);
	if (aa != bb)
		p[bb] = aa;
}

bool isSameGroup(int a, int b)
{
	int aa = find(a);
	int bb = find(b);
	return aa == bb;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int x, y;
		cin >> x >> y;
		doUnion(x, y);
		deg[x]++;
		deg[y]++;
	}


	int cnt = 0;
	for (int i = 1; i <= v; i++)
	{
		if (isSameGroup(i, 1))
		{
			cnt++;
		}
	}
	if (cnt != v)
	{
		cout << "NO";
		return 0;
	}

	int odd = 0;
	for (int i = 1; i <= v; i++)
	{
		if (deg[i] % 2 == 1)
		{
			odd++;
		}
	}

	if (odd == 0 || odd == 2) cout << "YES";
	else cout << "NO";

	return 0;
}