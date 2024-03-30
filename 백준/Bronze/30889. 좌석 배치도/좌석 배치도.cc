#include <bits/stdc++.h>

using namespace std;

using ll = long long;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	vector<vector<char>> board(10, vector<char>(20, '.'));
	while (tc--)
	{
		string seat;
		cin >> seat;
		int row = seat[0] - 'A';
		int col = stoi(seat.substr(1)) - 1;
		board[row][col] = 'o';
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << board[i][j];
		}
		cout << '\n';
	}


	return 0;
}