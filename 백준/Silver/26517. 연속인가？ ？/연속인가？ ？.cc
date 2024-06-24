#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

ll pfsum[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll k;
	cin >> k;
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll axb = a * k + b;
	ll cxd = c * k + d;

	if (axb == cxd)
		cout << "Yes " << axb;
	else
		cout << "No";

	return 0;
}