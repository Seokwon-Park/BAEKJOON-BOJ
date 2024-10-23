#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int v[10];
int bm = 0;

int check()
{
	if ((0b1011111000 & bm) > 0)
	{
		return 0;
	}
	else if (v[2] && v[0] && v[1] && v[8])
	{
		if (v[2] == v[0] && v[0] == v[1] && v[1] == v[8])
			return 8;
		return 2;
	}
	else
	{
		return 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while (n)
	{
		v[n % 10]++;
		bm |= (1 << n % 10);
		n /= 10;
	}

	cout << check();

	return 0;
}