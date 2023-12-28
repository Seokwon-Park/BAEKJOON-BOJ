#include <bits/stdc++.h>

using namespace std;

int dp[505];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> vp;
	vector<int> arr(n);


	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		vp.push_back({ a,b });
	}

	sort(vp.begin(), vp.end());

	for (int i = 0; i < n; i++)
	{
		arr[i] = vp[i].second;
		dp[i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}

	int dpmin = n - *max_element(dp, dp + n);
	cout << dpmin;


	return 0;
}
