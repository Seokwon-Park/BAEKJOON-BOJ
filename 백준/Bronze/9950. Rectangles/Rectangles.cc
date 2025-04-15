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

	while (1)
	{
		int l, w, a;
		cin >> l >> w >> a;
		if (l == 0 && w == 0 && a == 0) break;
		if (l == 0)
		{
			cout << a / w << ' ' << w << ' ' << a;
		}
		else if (w == 0)
		{
			cout << l << ' ' << a/l << ' ' << a;
		}
		else
		{
			cout << l << ' ' << w << ' ' << l*w;
		}
		cout << '\n';
	}
	

	return 0;
}