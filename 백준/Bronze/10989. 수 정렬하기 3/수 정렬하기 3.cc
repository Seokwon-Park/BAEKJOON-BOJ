#include <bits/stdc++.h>

using namespace std;

int arr[10005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int max = -1;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (input > max) max = input;
		arr[input]++;
	}

	

	for (int i = 0; i <= max; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			cout << i << '\n';
		}
	}

	return 0;
}