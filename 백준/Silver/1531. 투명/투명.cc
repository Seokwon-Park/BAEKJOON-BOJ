#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int b[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int t = 0; t < n; t++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1 - 1; i <= y2 - 1; i++)
		{
			for (int j = x1 - 1; j <= x2 - 1; j++)
			{
				b[i][j]++;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			cnt += (b[i][j] > m);
		}
	}
	cout << cnt;


	return 0;
}