#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.size();
	int r = 0;
	for (int i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
			r = i;
	}
	int c = n / r;

	vector<vector<char>> board(r, vector<char>(c));
	for (int i = 0; i < n; i++)
	{
		board[i % r][i / r] = s[i];
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << board[i][j];
		}
	}


	return 0;
}