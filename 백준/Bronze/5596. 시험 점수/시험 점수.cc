#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v(2);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int score;
			cin >> score;
			v[i] += score;
		}
	}

	cout << max(v[0], v[1]);

	return 0;
}