#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, x;
	cin >> n >> m >> x;
	vector<vector<char>> b(n, vector<char>(m, '.'));

	for (int i = 0; i < m; i++)
	{
		int h;
		cin >> h;
		for (int j = n - 1; j >= n - h; j--)
		{
			b[j][i] = '#';
		}

		if (h < x)
			b[n-x][i] = '-';
		else
			b[n-x][i] = '*';

		if (i % 3 == 2)
		{
			int j = n - x + 1;
			while (j< n && b[j][i] == '.')
			{
				b[j][i] = '|';
				j++;
			}
		}

	}


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