#include <bits/stdc++.h>

using namespace std;

int n;

int board[100005][3];
int dpmx[3];
int dpmn[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> board[i][j];
		}
	}

	dpmx[0] = board[0][0];
	dpmx[1] = board[0][1];
	dpmx[2] = board[0][2];

	dpmn[0] = board[0][0];
	dpmn[1] = board[0][1];
	dpmn[2] = board[0][2];

	for (int i = 1; i < n; i++)
	{
		int mx1 = dpmx[0];
		int mx2 = dpmx[1];
		int mx3 = dpmx[2];
		dpmx[0] = max(mx1, mx2) + board[i][0];
		dpmx[1] = max({ mx1, mx2, mx3}) + board[i][1];
		dpmx[2] = max(mx2,mx3) + board[i][2];

		int mn1 = dpmn[0];
		int mn2 = dpmn[1];
		int mn3 = dpmn[2];
		dpmn[0] = min(mn1,mn2) + board[i][0];
		dpmn[1] = min({ mn1,mn2,mn3 }) + board[i][1];
		dpmn[2] = min(mn2,mn3) + board[i][2];
	}

	cout << *max_element(dpmx, dpmx + 3) << ' ' << *min_element(dpmn, dpmn + 3);

	return 0;
}
