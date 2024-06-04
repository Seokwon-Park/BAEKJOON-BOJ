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

	int c, k, p;
	cin >> c >> k >> p;

	int ans = 0;
	for (int i = 1; i <= c; i++)
	{
		ans += i * k + p * i * i;
	}
	cout << ans;

	return 0;
}