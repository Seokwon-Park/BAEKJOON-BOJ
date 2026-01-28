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
using hashmap = unordered_map<key, value>;

ll gcd(ll a, ll b)
{
	while (b)
	{
		ll r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		ll x = 0;
		for (int i = 0; i < n - 1; i++)
		{
			ll gap = v[i + 1] - v[i];
			if (x == 0) x = gap;
			else x = gcd(x, gap);
		}
		if (x == 0) cout << "INFINITY";
		else cout << x;
		cout << '\n';
	}




	return 0;
}