#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int cost = 0;
	for (int i = 0; i < n; i++)
	{
		while (a[i] != 0)
		{
			if (a[i] > 0)
			{
				if (i < n-1 && a[i + 1] > 0)
				{
					if (i < n - 2 && a[i + 2] > 0 && a[i+1] <= a[i+2])
					{
						a[i]--;
						a[i + 1]--;
						a[i + 2]--;
						cost += 7;
					}
					else
					{
						a[i]--;
						a[i + 1]--;
						cost += 5;
					}
				}
				else
				{
					a[i]--;
					cost += 3;
				}
			}
		}
	}

	cout << cost;

	return 0;
}