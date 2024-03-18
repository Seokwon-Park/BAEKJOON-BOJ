#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

char board[51][51];
bool isRowOK[51];
bool isColOK[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'X')
			{
				isRowOK[i] = true;
				isColOK[j] = true;
			}
		}
	}

	int r = count(isRowOK, isRowOK + n, false);
	int c = count(isColOK, isColOK + m, false);

	cout << max(r, c);

	return 0;
}