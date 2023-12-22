#include <bits/stdc++.h>

using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int l = lcm(m, n);

		int answer = -1;
		if (x == m) x = 0;
		if (y == n) y = 0;
		for (int i = x; i <= l; i += m)
		{
			if (i == 0) continue;
			if (i % n == y)
			{
				answer = i;
				break;
			}
		}
		cout << answer << '\n';
	}
	
	return 0;
}