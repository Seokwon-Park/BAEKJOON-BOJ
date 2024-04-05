#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int& i : v)
		cin >> i;
	int k;
	cin >> k;
	sort(v.begin(), v.end());
	int ix = lower_bound(v.begin(), v.end(), k) - v.begin();
	int st = 0;
	if (ix == 0)
		st = 1;
	else
		st = v[ix - 1]+1;
	
	int cnt = 0;
	for (int i = st; i <= k; i++)
	{
		for (int j = k; j < v[ix]; j++)
		{
			if (i == j)continue;
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}
