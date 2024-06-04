#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int bb[405][405];

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
			int r, g, b;
			cin >> r >> g >> b;
			bb[i][j] = r * 2126 + g * 7152 + b * 722;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (bb[i][j] < 510000)
				cout << '#';
			else if (bb[i][j] < 1020000)
				cout << 'o';
			else if (bb[i][j] < 1530000)
				cout << '+';
			else if (bb[i][j] < 2040000)
				cout << '-';
			else
				cout << '.';
		}
		cout << '\n';
	}


	return 0;
}
