#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	string s;
	cin >> n >> s;

	for (ll i = 0; i< n; i++)
	{
		ll ix = s[i] - 'A';
		ix = (ix + (1LL << i)) % 26LL;
		s[i] = 'A' + ix;
	}
	cout << s;

	return 0;
}