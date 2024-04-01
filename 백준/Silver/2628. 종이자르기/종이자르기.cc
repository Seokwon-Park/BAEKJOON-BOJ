#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int w, h;
	cin >> w >> h;
	vector<int> row(1, 0), col(1, 0);
	row.push_back(h);
	col.push_back(w);
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		if (a == 0)
		{
			row.push_back(b);
		}
		else
		{
			col.push_back(b);
		}
	}
	sort(row.begin(), row.end());
	sort(col.begin(), col.end());
	
	int lrow = 0;
	int lcol = 0;
	for (int i = 0; i < row.size() - 1; i++)
	{
		lrow = max(row[i + 1] - row[i], lrow);
	}
	for (int i = 0; i < col.size() - 1; i++)
	{
		lcol = max(col[i + 1] - col[i], lcol);
	}

	cout << lrow * lcol;


	return 0;
}