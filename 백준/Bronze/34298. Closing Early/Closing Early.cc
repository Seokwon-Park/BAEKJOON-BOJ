
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll r, s, n;
	cin >> r >> s >> n;
	vector<int> v(n);
	for (int& i : v)
	{
		cin >> i;
	}

	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum % s == r % s)
		{
			cout << i;
			return 0;
		}
		sum += v[i];
	}

	if (sum % s == r % s)
	{
		cout << n;
		return 0;
	}
	cout << -1;

	return 0;
}