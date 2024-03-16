#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;

char board[9][9];

long long ans = INT_MIN;

void updatesq(string n)
{
	ll num = stoll(n);
	ll sq = sqrt(num);
	if (sq * sq == num)
		ans = max(ans, num);
	reverse(n.begin(), n.end());
	num = stoll(n);
	sq = sqrt(num);
	if (sq * sq == num)
		ans = max(ans, num);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	for (int y = 0; y < n; y ++)
		for (int x = 0; x < m; x ++)
			for (int dy = 0; dy < n; dy++)
				for (int dx = -m+1; dx < m; dx++)
				{
					string tmp = "";
					if (dx == 0 && dy == 0)
					{
						string tmp2(1, board[y][x]);
						updatesq(tmp2);
						continue;
					}
					int i = y; 
					int j = x;
					while (i>= 0 && j >= 0 && i < n && j < m)
					{
						tmp += board[i][j];
						updatesq(tmp);
						i += dy;
						j += dx;
					}
				}

	if (ans == INT_MIN)
		cout << -1;
	else
		cout << ans;

	return 0;
}