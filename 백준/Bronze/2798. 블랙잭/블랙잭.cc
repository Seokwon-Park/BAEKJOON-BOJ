#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), [](int a, int b) {
		return a > b;
		});

	int max = -1;
	for(int i =0; i< n-2; i++)
		for(int j =i + 1; j< n-1; j++)
			for (int k = j + 1; k < n; k++)
			{
				if (arr[i] + arr[j] + arr[k] <= m)
				{
					if (arr[i] + arr[j] + arr[k] <= max) continue;
					max = arr[i] + arr[j] + arr[k];
				}
			}

	cout << max;


	return 0;
}