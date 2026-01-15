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


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, x;
	cin >> n >> x;

	vector<ll> v;

	for (int i = 1; i <= n - 2; i++)
	{
		if (n - 1 - i <= x)
		{
			v.push_back(i);
			x -= n - 1 - i;
		}
		else
		{
			cout << i << ' ';
		}
	}

	if (x == 0)
	{
		cout << n << ' ';
		for (int i : v)
		{
			cout << i << ' ';
		}
		cout << n - 1 << ' ';
	}
	else
	{
		cout << -1;
	}


	return 0;
}