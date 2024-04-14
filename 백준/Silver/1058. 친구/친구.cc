#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int b[55][55];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		fill(b[i], b[i] + n, 0x3f3f3f);
		b[i][i] = 0;
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			if (c == 'Y')b[i][j] = 1;
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
			}
		}
	}
	
	vector<int> fs(n, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b[i][j] <= 2 && b[i][j] > 0)
			{
				fs[i]++;
			}
		}
	}

	cout << *max_element(fs.begin(), fs.end());

	return 0;
}
