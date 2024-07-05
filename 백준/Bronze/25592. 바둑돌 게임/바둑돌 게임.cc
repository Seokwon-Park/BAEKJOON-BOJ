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

	int m = 1;
	while (n >= m * 2 + 1)
	{
		n -= m * 2 + 1;
		m += 2;
	}
	if (n >= m)
	{
		cout << 0;
	}
	else
	{
		cout << m - n;
	}

	return 0;
}