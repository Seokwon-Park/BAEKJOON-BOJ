#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int quest = 0;
	for (int i = 0; i < n; i++)
	{
		int o = 0;
		int x = 0;
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] == 'O')o++;
			else x++;
		}
		if (o > x)
			quest++;
	}
	cout << quest;

	return 0;
}