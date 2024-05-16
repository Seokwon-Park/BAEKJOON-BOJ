#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& i : v)
		cin >> i;

	sort(v.begin(), v.end(), greater<int>());

	int ans = 0;
	for (int i = 0; i < k; i++)
	{
		ans += v[i];
	}

	ans -= k * (k - 1) / 2;
	cout << ans;

	return 0;
}