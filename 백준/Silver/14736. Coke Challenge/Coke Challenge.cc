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
	
	int n, k, a;
	cin >> n >> k >> a;

	int ans = INF;
	for (int i = 0; i < n; i++)
	{
		int t, s;
		cin >> t >> s;
		int drink = a * t;
		int x = k / drink;
		int total;
		if (k % drink == 0)
		{
			total = x * t + (x-1) * (s);
		}
		else
		{
			total = x * t + x * s + ((k % drink) / a);
		}
		ans = min(ans, total);
	}

	cout << ans;

	return 0;
}