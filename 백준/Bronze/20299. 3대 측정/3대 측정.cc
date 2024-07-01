#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, l;
	cin >> n >> k >> l;

	int ans = 0;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a + b + c >= k && a >= l && b >= l && c >= l)
		{
			ans++;
			v.push_back(a);
			v.push_back(b);
			v.push_back(c);
		}
	}
	cout << ans << '\n';
	for (auto i : v)
		cout << i << ' ';

	return 0;
}