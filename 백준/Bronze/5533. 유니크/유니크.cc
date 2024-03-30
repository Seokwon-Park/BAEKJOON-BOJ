#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int table[4][101];
int player[205][4];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		player[i][1] = a;
		player[i][2] = b;
		player[i][3] = c;
		table[1][a]++;
		table[2][b]++;
		table[3][c]++;
	}

	for (int i = 0; i < n; i++)
	{
		int ans = 0;
		if (table[1][player[i][1]] == 1)
			ans += player[i][1];
		if (table[2][player[i][2]] == 1)
			ans += player[i][2];
		if (table[3][player[i][3]] == 1)
			ans += player[i][3];
		cout << ans << '\n';
	}

	return 0;
}