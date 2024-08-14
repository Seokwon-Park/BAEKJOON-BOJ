#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

ll f[10005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	f[0] = 1;
	f[1] = 1;
	
	for (ll i = 2; i <= 10000; i++)
	{
		while (f[i - 1] % 10 == 0)
			f[i-1] /= 10;
		f[i] = f[i - 1] * i;
		f[i] %= 1'000'000'000;
	}

	int n;
	while (cin >> n)
	{
		cout << setw(5) << setfill(' ') << right << n << " -> " << f[n]%10 << '\n';
	}

	return 0;

}