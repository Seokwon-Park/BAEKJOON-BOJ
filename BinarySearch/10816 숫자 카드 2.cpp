#include <bits/stdc++.h>

using namespace std;

int arr[500001];
int n;

int lower_bound(int t, int n)
{
	int st = 0, en = n;
	while (st<en)
	{
		int mid = (st + en) / 2;
		if (arr[mid] >= t)
		{
			en = mid;
		}
		else if (arr[mid] < t)
		{
			st = mid + 1;
		}
	}
	return st;
}
int upper_bound(int t, int n)
{
	int st = 0, en = n;
	while (st < en)
	{
		int mid = (st + en) / 2;
		if (arr[mid] > t)
		{
			en = mid;
		}
		else if (arr[mid] <= t)
		{
			st = mid + 1;
		}
	}
	return st;
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
		//cout << std::upper_bound(arr, arr + n, k) - std::lower_bound(arr, arr+n, k) <<' ';
		cout << upper_bound(k, n) - lower_bound(k, n) <<' ';
	}
	return 0;
}
