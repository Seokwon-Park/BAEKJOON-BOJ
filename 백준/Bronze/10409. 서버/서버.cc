#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t;
	cin >> n >> t;
	int cur = 0;
	for (int i = 1; i <= n; i++)
	{
		int m;
		cin >> m;
		cur += m;
		if (cur > t) {
			cout << i - 1;
			return 0;
		}
	}
	cout << n;

	return 0;
}