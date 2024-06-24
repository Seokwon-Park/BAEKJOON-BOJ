#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

char b[5][61];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.size();

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4 * n + 1; j++)
		{
			if ((i == 0 || i == 4) && j % 4 == 2)
			{
				if ((j / 4) % 3 == 2)
					b[i][j] = '*';
				else
					b[i][j] = '#';
			}
			else if ((i == 1 || i == 3) && (j % 2 == 1 || j % 2 == 3))
			{
				if ((j / 4) % 3 == 2)
					b[i][j] = '*';
				else
					b[i][j] = '#';
			}
			else if (i == 2)
			{
				if (j % 4 == 2)
					b[i][j] = s[j / 4];
				else if (j % 4 == 0)
				{
					b[i][j] = '#';
					if ((j / 4) % 3 == 2 || (j / 4) % 3 == 0)
					{
						if (j > 0)
							b[i][j] = '*';
						else
							b[i][j] = '#';
					}
				}
				else
					b[i][j] = '.';
			}
			else
				b[i][j] = '.';
		}
	}

	if (n % 3 != 0)
		b[2][4 * n] = '#';

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4 * n + 1; j++)
		{
			cout << b[i][j];
		}
		cout << '\n';
	}



	return 0;
}