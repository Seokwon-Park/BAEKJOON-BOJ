#include <bits/stdc++.h>

using namespace std;

int a[105][105];
int b[105][105];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	cin >> m >> k;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int sum = 0;
			for (int l = 0; l < m; l++)
			{
				sum += a[i][l]*b[l][j];
			}
			cout << sum << ' ';
		}
		cout << '\n';
	}
	


	return 0;
}