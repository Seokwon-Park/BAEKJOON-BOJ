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

	int n;
	cin >> n;
	vector<int> v(n);

	for (int& i : v)
	{
		cin >> i;
	}

	int mx = *max_element(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (i + 1 < n)
		{
			ans = max(ans, min(v[i], v[i + 1]));
		}
		if (i + 2 < n)
		{
			vector<int> tmp = { v[i], v[i + 1], v[i + 2] };
			sort(tmp.begin(), tmp.end());
			ans = max(ans, tmp[1]);
		}
	}

	cout << ans;

	return 0;
}