#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	int sum = 0;
	int min = n;

	bool arr[10001];

	fill(arr, arr + n + 1, true);

	for (int i = 2; i < sqrt(n) + 1; i++)
	{
		if (arr[i])
		{
			int j = 2;
			while (i * j <= n)
			{
				arr[i * j] = false;
				j++;
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (i >= m && arr[i])
		{
			if (min > i)
			{
				min = i;
			}
			sum += i;
		}
	}

	if (sum == 0)
		cout << -1;
	else
		cout << sum << '\n' << min;


	return 0;
}
