#include <bits/stdc++.h>

using namespace std;

using ll = long long;

char b[105][105];
int cloud[105][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		fill(cloud[i], cloud[i] + w, -1);
		for (int j = 0; j < w; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 'c')
			{
				cloud[i][j] = 0;
				int dx = 1;
				while (j + dx < w)
				{
					cloud[i][j+dx] = dx;
					dx++;
				}
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << cloud[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}