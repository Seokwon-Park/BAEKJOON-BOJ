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

int v[10005];

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)break;

		ll sum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int x;
				cin >> x;
				if (j == m - 1)
				{
					sum += x;
					v[i] = x;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			ll g = gcd(v[i], sum);
			cout << v[i] / g << " / " << sum / g << '\n';
		}

	}

	return 0;
}
