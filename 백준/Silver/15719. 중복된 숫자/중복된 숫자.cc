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
	vector<bool> v(n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		if (v[m])
			ans = m;
		if (ans == 0)
		{
			v[m] = true;
		}
	}

	cout << ans;

	return 0;
}