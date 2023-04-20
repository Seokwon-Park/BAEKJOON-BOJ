#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int max = 0;
	int x, y;
	int arr[9][9];
	for(int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] >= max)
			{
				max = arr[i][j];
				x = i;
				y = j;
			}
		}

	cout << max << '\n';
	cout << x+1 << ' ' << y+1;
	return 0;
}
