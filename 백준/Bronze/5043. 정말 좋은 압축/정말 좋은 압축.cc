#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, b;
	cin >> n >> b;

	ll total = 0;
	for (ll i = 0; i <= b; i++)
	{
		total += (1LL << i);
	}

	if (n <= total)
	{
		cout << "yes";
	}
	else
	{
		cout << "no";
	}





	return 0;
}
