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

	int n, k, t;
	cin >> n >> k >> t;
	vector<ll> v(n);
	ll total = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		total += v[i];
	}
	
	sort(v.begin(), v.end(), greater<ll>());

	if (total % k != 0)
	{
		cout << "NO";
	}
	else
	{
		ll x = 0;
		for (int i = 0; i < total / k; i++)
		{
			x += v[i];
		}

		ll need = total - x;
		if (need > t)
		{
			cout << "NO";
		}
		else
		{
			cout << "YES";
		}
		
		 
	}

	return 0;
}