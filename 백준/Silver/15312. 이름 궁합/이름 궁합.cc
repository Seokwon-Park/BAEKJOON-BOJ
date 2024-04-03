#include <bits/stdc++.h>

using namespace std;

using ll = long long;
char m[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string a, b;
	cin >> a >> b;
	vector<vector<int>> v(a.size()*2-1, vector<int>());

	for (int i = 0; i < a.size(); i++)
	{
		v[0].push_back(m[a[i] - 'A']);
		v[0].push_back(m[b[i] - 'A']);
	}

	int i = 1;
	while (true)
	{
		for (int j = 0; j < v[i - 1].size()-1; j++)
		{
			v[i].push_back((v[i - 1][j] + v[i - 1][j + 1]) % 10);
		}
		if (v[i].size() == 2)break;
		i++;
	}

	cout << v[i][0] << v[i][1];

	

	return 0;
}