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

int n, m;
int v[1024][1024];
int segtree[1024 * 4][1024 * 4];

void initCol(int rowNode, int str, int enr, int colNode, int stc, int enc)
{
	if (stc == enc)
	{
		if (str == enr)
		{
			segtree[rowNode][colNode] = v[str][stc];
		}
		else
		{
			segtree[rowNode][colNode] = segtree[rowNode * 2][colNode] + segtree[rowNode * 2 + 1][colNode];
		}
		return;
	}

	int mid = (stc + enc) / 2;
	initCol(rowNode, str, enr, colNode * 2, stc, mid);
	initCol(rowNode, str, enr, colNode * 2 + 1, mid + 1, enc);

	segtree[rowNode][colNode] = segtree[rowNode][colNode * 2] + segtree[rowNode][colNode * 2 + 1];
}

void initRow(int node, int st, int en)
{
	if (st != en)
	{
		int mid = (st + en) / 2;
		initRow(node * 2, st, mid);
		initRow(node * 2 + 1, mid + 1, en);
	}

	initCol(node, st, en, 1, 0, n - 1);
}

void updateCol(int rowNode, int colNode, int stc, int enc, int r, int c, int diff)
{
	if (c < stc || c > enc) return;
	if (stc != enc)
	{
		int mid = (stc + enc) / 2;
		updateCol(rowNode, colNode * 2, stc, mid, r, c, diff);
		updateCol(rowNode, colNode * 2 + 1, mid + 1, enc, r, c, diff);
	}
	segtree[rowNode][colNode] += diff;
}


void updateRow(int node, int st, int en, int r, int c, int diff)
{
	if (r < st || r > en) return;

	if (st != en)
	{
		int mid = (st + en) / 2;
		updateRow(node * 2, st, mid, r, c, diff);
		updateRow(node * 2 + 1, mid + 1, en, r, c, diff);
	}
	updateCol(node, 1, 0, n - 1, r, c, diff);

}

ll queryCol(int rowNode, int colNode, int stc, int enc, int r1, int c1, int r2, int c2)
{
	if (enc < c1 || stc > c2) return 0;
	if (stc >= c1 && enc <= c2)
	{
		return segtree[rowNode][colNode];
	}

	int mid = (stc + enc) / 2;
	return queryCol(rowNode, colNode * 2, stc, mid, r1, c1, r2, c2) +
		queryCol(rowNode, colNode * 2 + 1, mid + 1, enc, r1, c1, r2, c2);
}

ll queryRow(int node, int st, int en, int r1, int c1, int r2, int c2)
{
	if (st > r2 || en < r1) return 0;
	if (st >= r1 && en <= r2)
	{
		return queryCol(node, 1, 0, n - 1, r1, c1, r2, c2);
	}
	int mid = (st + en) / 2;
	return queryRow(node * 2, st, mid, r1, c1, r2, c2) +
		queryRow(node * 2 + 1, mid + 1, en, r1, c1, r2, c2);
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}

	initRow(1, 0, n - 1);

	for (int i = 0; i < m; i++)
	{
		int w;
		cin >> w;
		if (w == 0)
		{
			int row, col, c;
			cin >> row >> col >> c;
			row--;
			col--; 
			int diff = c - v[row][col];
			v[row][col] = c;
			updateRow(1, 0, n - 1, row, col, diff);
		}
		else
		{
			int str, stc, enr, enc;
			cin >> str >> stc >> enr >> enc;
			str--;
			stc--;
			enr--;
			enc--;
			cout << queryRow(1, 0, n - 1, str, stc, enr, enc) << '\n';
		}
	}

	return 0;
}