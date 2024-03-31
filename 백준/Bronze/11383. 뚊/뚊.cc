#include <bits/stdc++.h>

using namespace std;

using ll = long long;

char b[11][11];
char b2[11][21];
char b3[11][21];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}

	bool isDiff = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m*2; j++)
		{
			cin >> b2[i][j];
			b3[i][j] = b[i][j / 2];
			if (b3[i][j] != b2[i][j])
				isDiff = true;
		}
	}
	if (isDiff)
		cout << "Not Eyfa";
	else
		cout << "Eyfa";


	return 0;
}