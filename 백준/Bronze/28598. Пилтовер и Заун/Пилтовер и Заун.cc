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

	ll x1, x2, n;
	cin >> x1 >> x2 >> n;
	if (n == 0 && x1 != x2)
		cout << "NO";
	else if (x1 < x2)
		cout << "NO";
	else if ((x1 - x2) % 2 != 0)
		cout << "NO";
	else if ((x1 - x2) / 2 < n)
		cout << "NO";
	else
		cout << "YES";

	return 0;
}
