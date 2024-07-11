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
	 
	int n;
	cin >> n;
	int ans = 0;
	if (n == 0)
	{
		cout << 1;
		return 0;
	}
	bitset<32> b(n);
	int ix = 0;
	while (b[b.size() - 1 - ix] == 0)
		ix++;

	ans = 32 - ix;
	
	cout << ans;

	return 0;
}