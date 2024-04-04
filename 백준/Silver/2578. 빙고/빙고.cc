#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int b[5][5];
vector<int> row(5, 5);
vector<int> col(5, 5);
vector<int> diag(2, 5); // \ / 순서

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	for (int i = 0; i < 25; i++)
	{
		cin >> b[i / 5][i % 5];
	}
	int ans = 0;
	bool isEnd = false;
	for (int ix = 0; ix < 25; ix++)
	{
		int call;
		cin >> call;
		for (int i = 0; i < 25; i++)
		{
			if (b[i / 5][i % 5] == call)
			{
				row[i / 5]--;
				col[i % 5]--;
				if (i / 5 == i % 5 && (i / 5 + i % 5 == 4))
				{
					diag[0]--;
					diag[1]--;
				}
				else if (i / 5 == i % 5)
				{
					diag[0]--;
				}
				else if(i / 5 + i % 5 == 4)
				{
					diag[1]--;
				}
			}
		}
		int res = count(row.begin(), row.end(), 0) + count(col.begin(), col.end(), 0) + count(diag.begin(), diag.end(), 0);
		if (!isEnd && res >= 3)
		{
			ans = ix + 1;
			isEnd = true;
		}
	}
	cout << ans;

	return 0;
}