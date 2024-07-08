#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> v2(n);
	for (int& i : v)
		cin >> i;
	for (int& i : v2)
		cin >> i;

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] * v2[i] < 0)
			ans += abs(v[i] - v2[i]);
		else
			ans += abs(v[i] + v2[i]);
	}
	cout << ans;

	return 0;
}