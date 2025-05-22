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

	int n, m;
	cin >> n >> m;

	ll total = 1;
	for (int i = 0; i < n; i++)
	{
		total *= m;
		total %= MOD;
	}

	ll zero = 1;
	for (int i = 0; i < n; i++)
	{
		zero *= m - 1;
		zero %= MOD;
	}
	total -= zero;
	if (total < 0)
	{
		total += MOD;
	}
	
	cout << total;


	return 0;
}