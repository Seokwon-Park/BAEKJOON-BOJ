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
	vector<int> v(2 * n);
	for (int& i : v)
		cin >> i;
	sort(v.begin(), v.end());
	int ans = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		int res = v[i] + v[2*n - i - 1];
		if (res < ans)
			ans = res;
	}
	cout << ans;

	return 0;
}