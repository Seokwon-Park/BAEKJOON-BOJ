#include <bits/stdc++.h>

using namespace std;

int ncr[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		ncr[i][i] = ncr[i][0] = 1;
		for (int j = 1; j < i; j++)
		{
			ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) %10007;
		}
	}

	cout << ncr[n][k];
	
	return 0;
}