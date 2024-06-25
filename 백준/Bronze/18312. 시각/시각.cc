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

	int n, k;
	cin >> n >> k;

	int hh = 0;
	int mm = 0;
	int ss = 0;
	int ans = 0;
	while (hh < n + 1)
	{
		if (ss / 10 == k || ss % 10 == k || mm % 10 == k || mm / 10 == k || hh / 10 == k || hh % 10 == k)ans++;
		ss++;
		if (ss >= 60)
		{
			mm++;
			ss = 0;
		}
		if (mm >= 60)
		{
			hh++;
			mm = 0;
		}
	}
	cout << ans;

	return 0;
}