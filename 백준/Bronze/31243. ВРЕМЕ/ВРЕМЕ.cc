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

	int mx = 0;
	int mn = INF;
	for (int i = 0; i < 3; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int ab = a * 60 + b;
		int cd = c * 60 + d;
		if (ab > cd)
		{
			cd += 24 * 60;
		}
		int res = cd - ab;
		mx = max(res, mx);
		mn = min(res, mn);
	}

	cout << mn / 60 << ':' << setw(2) << setfill('0') << mn % 60 << '\n';
	cout << mx / 60 << ':' << setw(2) << setfill('0') << mx % 60;
	return 0;
}