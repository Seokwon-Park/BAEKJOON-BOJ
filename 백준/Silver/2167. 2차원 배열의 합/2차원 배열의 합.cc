#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vec<vec<int>> board(n+1, vec<int>(m+1, 0));
	vec<vec<int>> pfsum(n+1, vec<int>(m+1, 0));
	for(int i = 1; i<=n;i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> board[i][j];
		}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			pfsum[i][j] = pfsum[i - 1][j] + pfsum[i][j - 1] - pfsum[i - 1][j - 1] + board[i][j];
		}

	int tc;
	cin >> tc;
	while (tc--)
	{
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		cout << pfsum[x][y] - pfsum[x][j- 1] - pfsum[i - 1][y] + pfsum[i - 1][j - 1] << '\n';;
	}

	return 0;
}