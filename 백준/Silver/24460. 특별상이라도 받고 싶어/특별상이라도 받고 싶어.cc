
#include <bits/stdc++.h>

using namespace std;

int board[1050][1050];

int func(int x, int y, int n)
{
	if (n == 1)
	{
		return board[y][x];

	}
	int half = n / 2;
	vector<int> four;
	four.push_back(func(x, y, half));
	four.push_back(func(x + half, y, half));
	four.push_back(func(x, y + half, half));
	four.push_back(func(x + half, y + half, half));

	sort(four.begin(), four.end());

	return four[1];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n * n; i++)
	{
		cin >> board[i / n][i % n];
	}

	if (n == 1)
	{
		cout << board[0][0];
		return 0;
	}

	cout << func(0, 0, n);

	return 0;
}