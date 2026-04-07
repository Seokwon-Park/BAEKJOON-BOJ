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

int v[1000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v[x]++;
	}

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v[x]--;
	}

	int ans = 0;
	for (int i = 1; i <= 1000000; i++)
	{
		if (v[i] > 0)
		{
			ans += v[i];
		}
	}

	cout << ans;

	return 0;
}