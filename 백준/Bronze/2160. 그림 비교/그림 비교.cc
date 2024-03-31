#include <bits/stdc++.h>

using namespace std;

using ll = long long;

char b[55][5][7];

int mindiff = INT_MAX;
int n1, n2;

void cmp(int ix1, int ix2)
{
	int diff = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (b[ix1][i][j] != b[ix2][i][j])
				diff++;
		}
	}
	if (diff < mindiff)
	{
		n1 = ix1;
		n2 = ix2;
		mindiff = diff;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 7; k++)
			{
				cin >> b[i][j][k];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			cmp(i, j);
		}
	}

	cout << n1+1 << ' ' << n2+1;

	return 0;
}