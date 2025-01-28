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
	
	ll n;
	cin >> n;
	while (n != 1)
	{
		cout << n << ' ';
		if (n % 2)
		{
			n = n * 3 + 1;
		}
		else
		{
			n /= 2;
		}
	}
	cout << n;


	return 0;
}
