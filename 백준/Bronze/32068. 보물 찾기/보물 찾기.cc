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

	int tc;
	cin >> tc;
	while (tc--)
	{
		int l, r, s;
		cin >> l >> r >> s;
		int ldiff = s - l;
		int rdiff = r - s;
		if (ldiff < rdiff)
			cout << ldiff * 2 + 1;
		else
			cout << rdiff * 2;
		cout << '\n';
	}

	return 0;
}