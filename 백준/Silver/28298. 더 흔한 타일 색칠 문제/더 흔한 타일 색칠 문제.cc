#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

char b[505][505];
int changed;
int n, m, k;


void change(int x, int y)
{
	vector<int> v(26, 0);
	for (int i = 0; i < n; i += k)
	{
		for (int j = 0; j < m; j += k)
		{
			v[b[y + i][x + j] - 'A']++;
		}
	}
	char ch = max_element(v.begin(), v.end()) - v.begin() + 'A';
	for (int i = 0; i < n; i += k)
	{
		for (int j = 0; j < m; j += k)
		{
			if (b[y + i][x + j] != ch)
			{
				changed++;
				b[y + i][x + j] = ch;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			change(i, j);
		}
	}

	cout << changed << '\n';
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