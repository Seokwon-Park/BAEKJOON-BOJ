#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, c;
	cin >> n >> c;
	vector<bool> boom(c+1, false);
	for (int i = 0; i < n; i++)
	{
		int cycle;
		cin >> cycle;
		if (!boom[cycle])
		{
			for (int j = cycle; j <= c; j += cycle)
			{
				boom[j] = true;
			}
		}
	}

	cout << count(boom.begin(), boom.end(), true);


	return 0;
}