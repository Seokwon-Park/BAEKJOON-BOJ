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

	int l, r, a;
	cin >> l >> r >> a;
	int gap = abs(l - r);
	if (gap >= a)
	{
		cout << (min(l, r) + a) * 2;
	}
	else
	{
		a -= gap;
		cout << (max(l, r)*2 + a / 2 * 2);
	}
	

	return 0;
}