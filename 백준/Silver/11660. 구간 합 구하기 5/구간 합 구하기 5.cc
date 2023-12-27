#include <bits/stdc++.h>

using namespace std;

int arr[1050][1050];
long long prefix[1050][1050];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}

	prefix[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++)
	{
		prefix[i][1] = prefix[i - 1][1] + arr[i][1];
		prefix[1][i] = prefix[1][i - 1] +arr[1][i];
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]+ arr[i][j];
		}
	}
	
	while (m--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		long long answer = prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1];
		cout << answer << '\n';

	}


	
	return 0;
}
