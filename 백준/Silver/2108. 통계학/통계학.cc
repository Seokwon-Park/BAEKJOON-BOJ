#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int sum = 0;
	vector<int> arr(n);
	map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		m[arr[i]]++;
	};

	sort(arr.begin(), arr.end());
	vector<pair<int, int>> mvec(m.begin(), m.end());

	sort(mvec.begin(), mvec.end(), [](pair<int, int> a, pair<int, int> b)
		{
			if (a.second == b.second)
			{
				return a.first < b.first;
			}
			return a.second > b.second;
		});

	int k;

	if (n == 1)
		k = mvec[0].first;
	else
	{
		if (mvec[0].second == mvec[1].second)
		{
			k = mvec[1].first;
		}
		else
		{
			k = mvec[0].first;
		}
	}

	cout << round((float)sum / (float)n)+0.0 << '\n'
		<< arr[n / 2] << '\n'
		<< k << '\n'
		<< *max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end());

	return 0;
}
