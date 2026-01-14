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

int v[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string s;
	ll x;
	int ans = 0;
	int jinju = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> x;
		if (s == "jinju") jinju = x;
		if (x <= 1000) v[x]++;
		else ans++;
	}

	for (int i = jinju + 1; i <= 1000; i++)
	{
		ans += v[i];
	}
	cout << jinju << '\n' << ans;

	return 0;
}