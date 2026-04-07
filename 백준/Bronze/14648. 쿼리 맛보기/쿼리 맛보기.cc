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

ll v[1005];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < q; i++)
	{
		int query;
		cin >> query;
		if (query == 1)
		{
			ll a, b;
			cin >> a >> b;
			ll res = 0;
			for (int i = a; i <= b; i++)
			{
				res += v[i];
			}
			cout << res;
			swap(v[a], v[b]);
		}
		else
		{
			ll a, b, c, d;
			cin >> a >> b >> c >> d;
			ll res = 0;
			for (int i = a; i <= b; i++)
			{
				res += v[i];
			}
			for (int i =c; i <= d; i++)
			{
				res -= v[i];
			}
			cout << res;
		}
		cout << '\n';
	}

	


	return 0;
}
