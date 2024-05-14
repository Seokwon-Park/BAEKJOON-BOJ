#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int v[11];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	int m;
	cin >> m;
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int menu;
		cin >> menu;
		ans += v[menu];
	}
	cout << ans;
	

	return 0;
}
