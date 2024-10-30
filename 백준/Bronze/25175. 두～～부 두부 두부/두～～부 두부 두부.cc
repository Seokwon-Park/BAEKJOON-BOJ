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
	
	int n, m, k;
	cin >> n >> m >> k;
	
	int tmp = (m + (k - 3) - 1);
	while (tmp <= 0)
	{
		tmp += n;
	}
	cout << tmp % n + 1;

	return 0;
}