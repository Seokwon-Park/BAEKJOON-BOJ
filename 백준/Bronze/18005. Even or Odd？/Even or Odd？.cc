#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int f[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	if (n % 2 == 1)
		cout << 0;
	else if (n % 2 == 0)
	{
		if ((n / 2) % 2 == 1)
			cout << 1;
		else
			cout << 2;
	}

	return 0;
}