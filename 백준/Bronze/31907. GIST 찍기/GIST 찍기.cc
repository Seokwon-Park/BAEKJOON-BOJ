#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

char b[300][400];

void drawbox(int x, int y, int n, char c)
{
	for (int i = y * n; i < (y + 1) * n; i++)
	{
		for (int j = x * n; j < (x + 1) * n; j++)
		{
			b[i][j] = c;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	drawbox(0, 0, n, 'G');
	drawbox(1, 0, n, '.');
	drawbox(2, 0, n, '.');
	drawbox(3, 0, n, '.');

	drawbox(0, 1, n, '.');
	drawbox(1, 1, n, 'I');
	drawbox(2, 1, n, '.');
	drawbox(3, 1, n, 'T');

	drawbox(0, 2, n, '.');
	drawbox(1, 2, n, '.');
	drawbox(2, 2, n, 'S');
	drawbox(3, 2, n, '.');

	for (int i = 0; i < n * 3; i++)
	{
		for (int j = 0; j < n * 4; j++)
		{
			cout << b[i][j];
		}
		cout << '\n';
	}

	return 0;
}