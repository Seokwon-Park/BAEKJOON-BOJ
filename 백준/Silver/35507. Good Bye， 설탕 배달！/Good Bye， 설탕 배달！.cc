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
		ll n;
		cin >> n;
		ll cura = 0;
		ll curb = 0;
		ll curc = 0;
		ll curp = 0;
		bool poss = 1;
		for (int i = 0; i < n; i++)
		{
			ll a, b, c, p;
			cin >> a >> b >> c >> p;
			if (cura < a)
			{
				curp += a - cura;
				cura = a;
			}
			if (curb < b)
			{
				curp += b - curb;
				curb = b;
			}
			if (curc < c)
			{
				curp += c - curc;
				curc = c;
			}
			if (curp >= p)
			{
				poss = 0;
			}
			else
			{
				curp++;
			}
		}
		cout << (poss ? "YES" : "NO") << '\n';
	}

	return 0;
}