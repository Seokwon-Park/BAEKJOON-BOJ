#include <bits/stdc++.h>

using namespace std;

char cube[6][3][3]; // u, f, d, b, l, r;
char cubecpy[6][3][3]; // u, f, d, b, l, r;
string color = "wryogb";
unordered_map<char, int> ctoix;

void init()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			fill(cube[i][j], cube[i][j] + 3, color[i]);
		}
	}
}

void rotate(char cmd, char dir)
{
	int itr = 0;
	int ix = ctoix[cmd];
	if (dir == '+')
		itr = 1;
	else
		itr = 3;


	for (int it = 0; it < itr; it++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cubecpy[ix][i][j] = cube[ix][i][j];
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cube[ix][i][j] = cubecpy[ix][2 - j][i];
			}
		}
	}
	for (int it = 0; it < itr; it++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (cmd == 'U')
			{
				int tmp = cube[ctoix['F']][0][i];
				cube[ctoix['F']][0][i] = cube[ctoix['R']][0][i];
				cube[ctoix['R']][0][i] = cube[ctoix['B']][2][2 - i];
				cube[ctoix['B']][2][2 - i] = cube[ctoix['L']][0][i];
				cube[ctoix['L']][0][i] = tmp;
			}
			else if (cmd == 'L')
			{
				int tmp = cube[ctoix['F']][i][0];
				cube[ctoix['F']][i][0] = cube[ctoix['U']][i][0];
				cube[ctoix['U']][i][0] = cube[ctoix['B']][i][0];
				cube[ctoix['B']][i][0] = cube[ctoix['D']][i][0];
				cube[ctoix['D']][i][0] = tmp;
			}
			else if (cmd == 'D')
			{
				int tmp = cube[ctoix['F']][2][i];
				cube[ctoix['F']][2][i] = cube[ctoix['L']][2][i];
				cube[ctoix['L']][2][i] = cube[ctoix['B']][0][2 - i];
				cube[ctoix['B']][0][2 - i] = cube[ctoix['R']][2][i];
				cube[ctoix['R']][2][i] = tmp;
			}
			else if (cmd == 'R')
			{
				int tmp = cube[ctoix['F']][i][2];
				cube[ctoix['F']][i][2] = cube[ctoix['D']][i][2];
				cube[ctoix['D']][i][2] = cube[ctoix['B']][i][2];
				cube[ctoix['B']][i][2] = cube[ctoix['U']][i][2];
				cube[ctoix['U']][i][2] = tmp;
			}
			else if (cmd == 'F')
			{
				int tmp = cube[ctoix['U']][2][i];
				cube[ctoix['U']][2][i] = cube[ctoix['L']][2-i][2];
				cube[ctoix['L']][2-i][2] = cube[ctoix['D']][0][2 - i];
				cube[ctoix['D']][0][2-i] = cube[ctoix['R']][i][0];
				cube[ctoix['R']][i][0] = tmp;
			}
			else if (cmd == 'B')
			{
				int tmp = cube[ctoix['D']][2][i];
				cube[ctoix['D']][2][i] = cube[ctoix['L']][i][0];
				cube[ctoix['L']][i][0] = cube[ctoix['U']][0][2 - i];
				cube[ctoix['U']][0][2 - i] = cube[ctoix['R']][2-i][2];
				cube[ctoix['R']][2 - i][2] = tmp;
			}
		}
	}

}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ctoix['U'] = 0;
	ctoix['F'] = 1;
	ctoix['D'] = 2;
	ctoix['B'] = 3;
	ctoix['L'] = 4;
	ctoix['R'] = 5;

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;

		init();

		for (int i = 0; i < n; i++)
		{
			string cmd;
			cin >> cmd;

			rotate(cmd[0], cmd[1]);

			//for (int i = 0; i < 3; i++)
			//{
			//	for (int j = 0; j < 3; j++)
			//	{
			//		cout << cube[0][i][j];
			//	}
			//	cout << '\n';
			//}
			//cout << '\n';
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << cube[0][i][j];
			}
			cout << '\n';
		}
	}

	return 0;
}
