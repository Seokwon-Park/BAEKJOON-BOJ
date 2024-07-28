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

	ll n;
	cin >> n;

	ll noRecur = (n - 2) % MOD;

	ll a = 1; 
	ll b = 1;
	for (int i = 0; i <= n-3; i++)
	{
		ll tmp = (a + b) %MOD;
		a = b;
		b = tmp;
	}
	cout << b << ' ' << noRecur;


	return 0;
}