#include <bits/stdc++.h>

using namespace std;

int arr[1005];
vector<int> two;
int n;

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i{ 0 }; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i= 0 ; i < n; i++)
	{
		for (int j= i ; j < n; j++)
		{
			two.push_back(arr[i] + arr[j]);
		}
	}

	sort(two.begin(), two.end());

	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (binary_search(two.begin(), two.end(), arr[i] - arr[j]))
			{
				cout << arr[i];
				return 0;
			}
		}
	}

	return 0;
}
