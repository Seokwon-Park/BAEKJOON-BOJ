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

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			b[i][j] = c - '0';
		}
	}

	int mx = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int k = b[i][j];
			int off = 0;
			int len = 0;
			while (i + off < n && j + off < m)
			{
				if (b[i + off][j] == k && b[i][j + off] == k && b[i + off][j + off] == k)
					len = off + 1;
				off++;
			}
			mx = max(mx, len * len);
		}
	}

	cout << mx;

	return 0;
}
