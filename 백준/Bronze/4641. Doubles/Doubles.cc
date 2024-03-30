#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		int n;
		cin >> n;
		if (n == -1)break;
		vector<int> v;
		v.push_back(n);
		int ans = 0;
		while (1)
		{
			int m;
			cin >> m;
			if (m == 0) break;
			v.push_back(m);
		}
		sort(v.begin(), v.end());
		for (int i : v)
		{
			if (binary_search(v.begin(), v.end(), i * 2))
				ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}