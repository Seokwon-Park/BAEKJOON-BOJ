#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		vector<int> sgn(n);
		for (int i = 0; i < n; i++)
		{
			cin >> sgn[i];
		}

		int cnt = 0;
		for (int i = 0; i < m; i++)
		{
			int k;
			cin >> k;
			if (binary_search(sgn.begin(), sgn.end(), k))
				cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}
