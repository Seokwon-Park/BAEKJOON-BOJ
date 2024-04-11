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
	sort(v.begin(), v.end());
	int ans = INT_MIN;
	do
	{
		int res = 0;
		for (int i = 0; i < n - 1; i++)
		{
			res += abs(v[i] - v[i + 1]);
		}
		ans = max(res, ans);
	} while (next_permutation(v.begin(), v.end()));
	cout << ans;

	return 0;
}