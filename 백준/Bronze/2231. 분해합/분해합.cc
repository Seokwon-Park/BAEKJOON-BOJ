#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int val = i;
		int sum = 0;
		sum += i;
		while (val % 10)
		{
			sum += val % 10;
			val /= 10;
		}
		if (sum == n)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;

	return 0;
}