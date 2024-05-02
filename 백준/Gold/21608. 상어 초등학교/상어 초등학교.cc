#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int n;
int b[21][21];
bool isLike[405][405]; // is a like b?
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void findLoc(int m)
{
	int llike = 0;
	int lempty = 0;
	int lx = 20;
	int ly = 20;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b[i][j] != 0) continue;
			int empty = 0;
			int like = 0;
			for (int k = 0; k < 4; k++)
			{
				int tx = j + dx[k];
				int ty = i + dy[k];
				if (tx < 0 || ty < 0 || tx >= n || ty >= n) continue;
				if (b[ty][tx] == 0)
					empty++;
				else if (isLike[m][b[ty][tx]])
					like++;
			}
			if (like > llike)
			{
				llike = like;
				lempty = empty;
				lx = j;
				ly = i;
			}
			else if (like == llike)
			{
				if (empty > lempty)
				{
					lempty = empty;
					lx = j;
					ly = i;
				}
				else if (empty == lempty)
				{
					if (i < ly)
					{
						lx = j;
						ly = i;
					}
					else if (i == ly)
					{
						if(j < lx)
						{
							lx = j;
						}
					}
				}
			}
		}
	}
	b[ly][lx] = m;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n * n; i++)
	{
		int m, l1, l2, l3, l4;
		cin >> m >> l1 >> l2 >> l3 >> l4;
		isLike[m][l1] = true;
		isLike[m][l2] = true;
		isLike[m][l3] = true;
		isLike[m][l4] = true;
		findLoc(m);

		//for (int t = 0; t < n; t++)
		//{
		//	for (int j = 0; j < n; j++)
		//	{
		//		cout << b[t][j];
		//	}
		//	cout << '\n';
		//}
		//cout << '\n';

	}


	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int like = 0;
			for (int k = 0; k < 4; k++)
			{
				int tx = j + dx[k];
				int ty = i + dy[k];
				if (tx < 0 || ty < 0 || tx >= n || ty >= n) continue;
				if (isLike[b[i][j]][b[ty][tx]])
					like++;
			}
			int res = 1;
			for (int k = 0; k < like; k++)
			{
				res *= 10;
			}
			res /= 10;
			ans += res;
		}
	}

	cout << ans;


	return 0;
}
