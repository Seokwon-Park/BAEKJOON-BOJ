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

	int q;
	cin >> q;
	while (q--)
	{
		ll a, b;
		cin >> a >> b;
		cout << (b % a == 0 && a < b) << '\n';
	}


	return 0;
}