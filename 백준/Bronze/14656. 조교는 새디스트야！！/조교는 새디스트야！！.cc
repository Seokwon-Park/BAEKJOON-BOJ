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
	vector<int> v(n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		if (v[i] != i)
			ans++;
	}
	cout << ans;

	return 0;
}