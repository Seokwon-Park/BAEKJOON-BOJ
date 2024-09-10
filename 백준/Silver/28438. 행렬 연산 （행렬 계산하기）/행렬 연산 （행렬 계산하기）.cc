#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;
	vector<int> row(n);
	vector<int> col(m);
	for (int i = 0; i < q; i++)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1)
		{
			int r, v;
			cin >> r >> v;
			row[r - 1] += v;
		}
		else
		{
			int c, v;
			cin >> c >> v;
			col[c - 1] += v;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << row[i] + col[j]<< ' ';
		}
		cout << '\n';
	}

	return 0;
}

