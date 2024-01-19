#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		int n;
		cin >> n;
		vector<bool> is_open(n+1, true);
		for (int i = 2; i <= n; i++)
		{
			for (int j = i; j <= n; j += i)
			{
				is_open[j] = !is_open[j];
			}
		}

		int answer = 0;
		for (int i = 1; i <= n; i++)
		{
			if (is_open[i]) answer++;
		}
		cout << answer << '\n';
	}

	return 0;
}