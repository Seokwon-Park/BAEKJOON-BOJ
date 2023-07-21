#include <bits/stdc++.h>

using namespace std;

int arr[500001];
int n;

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
		cout << std::upper_bound(arr, arr + n, k) - std::lower_bound(arr, arr+n, k) <<' ';
	}
	return 0;
}
