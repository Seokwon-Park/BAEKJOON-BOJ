#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int n;
char b[55][55];

int checkRow(int r1)
{
	int res1 = 0;
	int candy = 0;
	char prev = '\0';
	for (int i = 0; i < n; i++)
	{
		if (b[r1][i] == prev)
		{
			candy++;
		}
		else
		{
			prev = b[r1][i];
			res1 = max(res1, candy);
			candy = 1;
		}
	}
	res1 = max(res1, candy);

	return res1;
}
int checkCol(int c1) 
{
	int res1 = 0;
	int candy = 0;
	char prev = '\0';
	for (int i = 0; i < n; i++)
	{
		if (b[i][c1] == prev)
		{
			candy++;
		}
		else
		{
			prev = b[i][c1];
			res1 = max(res1, candy);
			candy = 1;
		}
	}
	res1 = max(res1, candy);

	return res1;
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int rowRes = 0; // row끼리 스왑한 결과중 최댓값
			int colRes = 0; // col끼리 스왑한 결과중 최댓값
			if (i < n - 1)
			{
				swap(b[i][j], b[i + 1][j]);
				rowRes = max(rowRes, checkRow(i));
				rowRes = max(rowRes, checkRow(i+1));
				rowRes = max(rowRes, checkCol(j));
				swap(b[i][j], b[i + 1][j]);

			}
			if (j < n - 1)
			{
				swap(b[i][j], b[i][j + 1]);
				colRes =max(colRes, checkCol(j));
				colRes =max(colRes, checkCol(j+1));
				colRes =max(colRes, checkRow(i));
				swap(b[i][j], b[i][j + 1]);
			}
			ans = max(ans, max(colRes, rowRes));
		}
	}

	cout << ans;

	return 0;
}