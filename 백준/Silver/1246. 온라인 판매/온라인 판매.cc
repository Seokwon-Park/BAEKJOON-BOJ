#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v(m);
	for (int i = 0; i < m; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int ans = INT_MIN;
	int price = 0;
	for (int i = 0; i < m; i++)
	{
		if (v.size() - i > n)continue;
		int res = v[i] * (v.size() - i);
		if (res > ans)
		{
			ans = res;
			price = v[i];
		}
	}
	cout << price << ' ' << ans;

	return 0;
}