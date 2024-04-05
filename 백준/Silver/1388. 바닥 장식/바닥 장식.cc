#include <bits/stdc++.h>

using namespace std;

using ll = long long;

char b[51][51];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int vert = 0;
	int hori = 0;

	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == '-')
				cnt++;
			else
				if (cnt > 0)
				{
					vert++;
					cnt = 0;
				}
		}
		if (cnt > 0)
		{
			vert++;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (b[j][i] == '|')
				cnt++;
			else
				if (cnt > 0)
				{
					hori++;
					cnt = 0;
				}
		}
		if (cnt > 0)
		{
			vert++;
		}
	}

	cout << vert + hori;

	return 0;
}