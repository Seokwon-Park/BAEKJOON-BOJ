#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	while (1)
	{
		cin >> t;
		if (t== 0) break;
		int m, n;
		cin >> m >> n;
		for (int i = 0; i < t; i++)
		{
			int x, y; 
			cin >> x >> y;
			if (x == m || y == n)
			{
				cout << "divisa";
			}
			else if (x > m && y > n)
			{
				cout << "NE";
			}
			else if (x > m && y < n)
			{
				cout << "SE";
			}
			else if (x < m && y > n)
			{
				cout << "NO";
			}
			else if (x < m && y < n)
			{
				cout << "SO";
			}
			cout << '\n';
		}
	}

	return 0;
}