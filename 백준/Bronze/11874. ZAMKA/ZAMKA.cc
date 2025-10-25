#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l, d, x;
	cin >> l >> d >> x;
	
	int mn = INF;
	int mx = 0;
	for (int i = l; i <= d; i++)
	{
		int tmp = i;
		int res = 0;
		while (tmp)
		{
			res += tmp % 10;
			tmp /= 10;
		}
		if (res == x)
		{
			mn = min(mn, i);
			mx = max(mx, i);
		}
	}

	cout << mn << '\n' << mx;
	return 0;
}
