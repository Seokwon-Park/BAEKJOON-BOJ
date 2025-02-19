#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

char v[25][25];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	char dir;
	int n;
	cin >> dir >> n;
	int bin = (1 << 1) + (1 << 2) + (1 << 5) + (1 << 8);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
			if (((1 << (v[i][j] - '0')) & bin) == 0)
			{
				v[i][j] = '?';
			}
			else if (v[i][j] == '2')
			{
				v[i][j] = '5';
			}
			else if (v[i][j] == '5')
			{
				v[i][j] = '2';
			}
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dir == 'D' || dir == 'U')
			{
				cout << v[n - i - 1][j] << ' ';
			}
			if (dir == 'L' || dir == 'R')
			{
				cout << v[i][n - j - 1] << ' ';
			}
		}
		cout << '\n';
	}




	return 0;
}



