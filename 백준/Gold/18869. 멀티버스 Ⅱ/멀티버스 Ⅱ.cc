#include<bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	vector<vector<int>> ori(m);
	vector<vector<int>> zip(m, vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int n;
			cin >> n;
			ori[i].push_back(n);
		}
	}
	vector<vector<int>> unic = ori;

	for (int i = 0; i < m; i++)
	{
		sort(unic[i].begin(), unic[i].end());
		unic.erase(unique(unic.begin(), unic.end()),unic.end());
		for (int j = 0; j < n; j++)
		{
			zip[i][j] =  lower_bound(unic[i].begin(), unic[i].end(), ori[i][j]) - unic[i].begin();
		}
	}

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = i+1; j < m; j++)
		{
			if (zip[i] == zip[j])
				ans++;
		}
	}

	cout << ans;

	return 0;
}