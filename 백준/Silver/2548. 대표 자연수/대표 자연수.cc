#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	int presum = 0;
	int postsum = 0;
	int first = v[0];
	for (int i = 0; i < n; i++)
	{
		postsum += v[i] - first;
	}
	//cout << postsum << '\n';
	int mindiff = postsum;
	int ans = v[0];
	for (int i = 1; i < n; i++)
	{
		int diff = v[i] - v[i - 1];
		presum += diff * i;
		postsum -= diff * (n - i);
		if (presum + postsum < mindiff)
		{
			mindiff = presum + postsum;
			ans = v[i];
		}
	}
	cout << ans;

	return 0;
}
