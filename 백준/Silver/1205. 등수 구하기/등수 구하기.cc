#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, p;
	cin >> n >> m >> p;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	if (n == 0)
	{
		cout << 1;
		return 0;
	}
	int ix = 0;
	while (m < v[ix])
	{
		ix++;
		if (ix == n) break;
	}
	if (n < p)
		cout << ix + 1;
	else if (*min_element(v.begin(), v.end()) >= m)
		cout << -1;
	else
		cout << ix + 1;

	return 0;
}