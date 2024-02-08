#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	int n;
	cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		a[i] = a[i - 1] + num;
	}

	int m;
	cin >> m;
	vector<int> b(m + 1);
	for (int i = 1; i <= m; i++)
	{
		int num;
		cin >> num;
		b[i] = b[i - 1] + num;
	}
	
	vector<int> avec;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			avec.push_back(a[j] - a[i]);

	vector<int> bvec;
	for (int i = 0; i < m; i++)
		for (int j = i + 1; j <= m; j++)
			bvec.push_back(b[j] - b[i]);

	sort(avec.begin(), avec.end());
	sort(bvec.begin(), bvec.end());

	long long ans = 0;
	for (int i = 0; i < avec.size(); i++)
	{
		ans += upper_bound(bvec.begin(), bvec.end(), t - avec[i]) - lower_bound(bvec.begin(), bvec.end(), t - avec[i]);
	}

	cout << ans;


	return 0;
}