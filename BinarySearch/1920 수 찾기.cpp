#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int n;

int bin_search(int t)
{
	int st = 0, en = n - 1;
	while (st <= en)
	{
		int mid = (st + en) / 2;
		if (t < arr[mid])
		{
			en = mid - 1;
		}
		else if (t > arr[mid])
		{
			st = mid + 1;
		}
		else 
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int m;
	cin >> m;
	while (m--)
	{
		int k;
		cin >> k;
		cout << bin_search(k) <<'\n';
	}
	return 0;
}
