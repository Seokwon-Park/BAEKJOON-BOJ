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
 
	while (1)
	{
		ll n, k;
		cin >> n >> k;
		if (n == 0 && k == 0) break;
		if (n - k < k) k = n - k;
		ll res = 1;
		for (int i = 0; i < k; i++)
		{
			res *= n -i;
			res /= i + 1;
		}
		cout << res << '\n';
	}

	return 0;
}
