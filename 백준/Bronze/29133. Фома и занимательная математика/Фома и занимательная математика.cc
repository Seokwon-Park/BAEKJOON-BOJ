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

	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<bool> res(3);
	res[0] = (a + b + c == d);
	res[1] = (a * a + b * b + c * c == d);
	res[2] = (a * a * a + b * b * b + c * c * c == d);

	int xcnt = count(res.begin(), res.end(), true);
	if (xcnt == 1)
	{
		if (res[0] == true) cout << 1;
		if (res[1] == true) cout << 2;
		if (res[2] == true) cout << 3;
	}
	else
		cout << -1;


	return 0;
}