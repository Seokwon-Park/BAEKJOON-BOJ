
#include <bits/stdc++.h>

using namespace std;

vector<int> p(100005, -1);

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool isdiff(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b)return false;
	if (p[a] < p[b]) p[b] = a;
	else p[a] = b;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		if (!isdiff(a, b)) // 같은 그룹인데 연결하려고 하면 끊는다.
		{
			cnt++;
		}
	}

	for (int i = 1; i < n; i++)
	{
		if (isdiff(i, i + 1))
		{
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
