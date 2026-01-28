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

	int n, m;
	while (cin >> m >> n)
	{
		if (n == 0 && m == 0) break;
		while (m != 1)
		{
			ll d = n / m + 1;
			while (1)
			{
				ll deno = n * d;
				ll nume = m * d - n;

				ll g = gcd(deno, nume);
				deno /= g;
				nume /= g;
				if (deno < 1000000)
				{
					cout << d << ' ';

					n = deno;
					m = nume;
					break;
				}
				d++;
			}
		}
		cout << n;
		cout << '\n';
	}
	

	return 0;
}