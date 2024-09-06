#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int m = 1;
	for (int i = 2; i * i <= n; i++)
	{
		if (n%i == 0)
		{
			m = n/i;
			break;
		}
	}

	cout << n -m;

	return 0;
}