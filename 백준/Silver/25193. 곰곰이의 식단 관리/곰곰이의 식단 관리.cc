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
	string s;
	cin >> n >> s;
	int div = 0;
	for (auto c : s)
	{
		if (c != 'C')
			div++;
	}
	n -= div;
	cout << n / (div+1) + (n % (div+1) == 0 ? 0 : 1);

	return 0;
}