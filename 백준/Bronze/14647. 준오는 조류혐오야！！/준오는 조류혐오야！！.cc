#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> b(n, vector<int>(m));
	vector<int> rows(n, 0);
	vector<int> cols(m, 0);
	int ncnt = 0;
	for(int i =0; i<n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
			int tmp = b[i][j];
			while(tmp)
			{
				if (tmp%10 == 9)
				{
					rows[i]++;
					cols[j]++;
					ncnt++;
				}
				tmp /= 10;
			}
		}
	int rowmax = *max_element(rows.begin(), rows.end());
	int colmax = *max_element(cols.begin(), cols.end());
	int res = max(rowmax, colmax);
	cout << ncnt - res;


	return 0;
}