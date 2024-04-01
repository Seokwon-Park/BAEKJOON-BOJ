#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = INT_MIN;
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		vector<int> ansv;
		ansv.push_back(n);
		ansv.push_back(i);
		int cur = n;
		int nxt = i;
		int len= 2;
		while (cur - nxt >= 0)
		{
			int tmp = cur - nxt;
			ansv.push_back(tmp);
			cur = nxt;
			nxt = tmp;
			len++;
		}
		if (len > ans)
		{
			ans = len;
			v = ansv;
		}
	}
	cout << ans << '\n';
	for (int i : v)
		cout << i << ' ';

	return 0;
}