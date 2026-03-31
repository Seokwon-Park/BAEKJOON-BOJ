#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
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

	int t;
	cin >> t;
	while (t--)
	{
		ll a, n;
		cin >> a >> n;
		string s;
		while (a)
		{
			int res = a % n;
			if (res >= 10)
			{
				s += res - 10 + 'A';
			}
			else
			{
				s += res + '0';
			}
			a /= n;
		}

		string rev = s;
		reverse(rev.begin(), rev.end());
		cout << (s == rev) << '\n';
	}

	return 0;
}