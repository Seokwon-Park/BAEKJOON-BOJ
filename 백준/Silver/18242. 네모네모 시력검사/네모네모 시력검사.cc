#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

char b[105][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (b[i][j] == '#')
			{
				int top = 1;
				int left = 1;
				while (b[i][j + top] == '#') top++;
				while (b[i+left][j] == '#') left++;
				if (top < left)
				{
					cout << "UP";
					return 0;
				}
				else if (top > left)
				{
					cout << "LEFT";
					return 0;
				}
				else
				{
					int bot = 1;
					int right = 1;
					while (b[i + top - 1][j + bot] == '#')bot++;
					while (b[i+right][j + top -1] == '#')right++;
					if (bot < right)
					{
						cout << "DOWN";
						return 0;
					}
					else if (bot > right)
					{
						cout << "RIGHT";
						return 0;
					}
				}
			}
		}
	}

	


	return 0;
}