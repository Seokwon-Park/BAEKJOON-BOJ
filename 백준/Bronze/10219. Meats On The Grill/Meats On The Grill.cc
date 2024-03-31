#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int h, w;
		cin >> h >> w;
		vector<vector<char>> b(h, vector<char>(w)) ;
		for (auto& v : b)
			for (char& c : v)
				cin >> c;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w / 2; j++)
			{
				swap(b[i][j], b[i][w - j - 1]);
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w ; j++)
			{
				cout << b[i][j];
			}
			cout << '\n';
		}
	}

	return 0;
}