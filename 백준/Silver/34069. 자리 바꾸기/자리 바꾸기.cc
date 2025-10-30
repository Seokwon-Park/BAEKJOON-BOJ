#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

vector<vector<int>> b;

void rotate(int x, int y, int xx, int yy)
{
	if (x > xx || y > yy) return;

	auto bcopy = b;
	for (int i = x; i < xx; i++)
	{
		bcopy[y][i] = b[y][i + 1];
	}
	for (int i = xx; i > x; i--)
	{
		bcopy[yy][i] = b[yy][i - 1];
	}
	for (int i = y; i < yy; i++)
	{
		bcopy[i][xx] = b[i+1][xx];
	}
	for (int i = yy; i > y; i--)
	{
		bcopy[i][x] = b[i-1][x];
	}
	b.swap(bcopy);
	rotate(x + 1, y + 1, xx - 1, yy - 1);

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	b.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}

	if (n % 2 && m % 2)
	{
		cout << "No";
	}
	else
	{
		cout << "Yes\n";
		rotate(0, 0, m-1, n-1);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << b[i][j] << ' ';
			}
			cout << '\n';
		}
	}


	return 0;
}