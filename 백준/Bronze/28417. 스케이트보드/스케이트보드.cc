#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int res = 0;
		vector<int> a(2);
		cin >> a[0] >> a[1];
		res += max(a[0], a[1]);
		vector<int> b(5);
		for (int j = 0; j < 5; j++)
		{
			cin >> b[j];
		}
		sort(b.begin(), b.end(), greater<int>());
		res += b[0] + b[1];
		ans = max(ans, res);
	}

	cout << ans;

	return 0;
}