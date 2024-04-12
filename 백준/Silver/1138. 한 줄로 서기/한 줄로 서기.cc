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
	for (int& i : v)
	{
		cin >> i;
	}

	vector<int> ans(n);
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (cnt == v[i - 1] && ans[j] == 0)
			{
				ans[j] = i;
				break;
			}
			if (ans[j] == 0 || ans[j] > i) cnt++;

		}
	}

	for (int i : ans)
		cout << i << ' ';

	return 0;
}