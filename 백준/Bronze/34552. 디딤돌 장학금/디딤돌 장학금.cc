#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
//const int MOD = 1'000'000'007;
const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> m(11);
	for (int& i : m)
	{
		cin >> i;
	}

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int b, s;
		double l;
		cin >> b >> l >> s;
		if (l >= 2.0 && s >= 17)
		{
			ans += m[b];
		}
	}
	cout << ans;
	
	return 0;
}