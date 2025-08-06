#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll a, b;
	cin >> a >> b;
	ll res = 0;
	ll yellow = 1;
	for (ll i = 0; i <= b; i++)
	{
		res = res + (a - 2) * i + 1;
	}
	cout << res; 

	return 0;
}