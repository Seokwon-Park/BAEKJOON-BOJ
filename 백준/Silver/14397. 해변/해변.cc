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

int b[55][55];
int n, m;

bool isIn(int i, int j)
{
	if (i < 0 || i >= n || j < 0 || j >= m)return false;
	else return true;
}

int check(int i, int j)
{
	return b[i][j] == 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			b[i][j] = (c == '.' ? 0 : 1);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (b[i][j] == 1)
			{
				if (i % 2)
				{
					if (isIn(i, j - 1)) ans += check(i, j - 1);
					if (isIn(i, j + 1)) ans += check(i, j + 1);
					if (isIn(i - 1, j + 1)) ans += check(i - 1, j + 1);
					if (isIn(i - 1, j)) ans += check(i - 1, j);
					if (isIn(i + 1, j + 1)) ans += check(i + 1, j + 1);
					if (isIn(i + 1, j)) ans += check(i + 1, j);
				}
				else
				{
					if (isIn(i, j - 1)) ans += check(i, j - 1);
					if (isIn(i, j + 1)) ans += check(i, j + 1);
					if (isIn(i - 1, j - 1)) ans += check(i - 1, j - 1);
					if (isIn(i - 1, j)) ans += check(i - 1, j);
					if (isIn(i + 1, j - 1)) ans += check(i + 1, j - 1);
					if (isIn(i + 1, j)) ans += check(i + 1, j);
				}
			}
		}
	}

	cout << ans;


	return 0;
}