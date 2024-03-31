#include <bits/stdc++.h>

using namespace std;

char c[256];
char b[105][105];
char bcpy[105][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	c['.'] = '.';
	c['O'] = 'O';
	c['-'] = '|';
	c['|'] = '-';
	c['/'] = '\\';
	c['\\'] = '/';
	c['^'] = '<';
	c['<'] = 'v';
	c['v'] = '>';
	c['>'] = '^';

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
			bcpy[i][j] = b[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			b[m-j-1][i] = c[bcpy[i][j]];
		}
	}
	swap(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << b[i][j];
		}
		cout << '\n';
	}


	return 0;
}