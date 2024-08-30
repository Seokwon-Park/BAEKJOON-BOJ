#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int b[705][705];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			b[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int zero, one, two;
		cin >> zero >> one >> two;
		vector<int> v;
		for (int i = 0; i < zero; i++)
			v.push_back(0);
		for (int i = 0; i < one; i++)
			v.push_back(1);
		for (int i = 0; i < two; i++)
			v.push_back(2);

		int ix = 0;
		for (int y = m - 1; y >= 0; y--)
		{
			b[y][0] += v[ix++];
		}
		for (int x = 1; x < m; x++)
		{
			b[0][x] += v[ix++];
		}
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < m; j++)
		{
			b[i][j] = max({ b[i - 1][j], b[i][j - 1], b[i - 1][j - 1] });
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << b[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}