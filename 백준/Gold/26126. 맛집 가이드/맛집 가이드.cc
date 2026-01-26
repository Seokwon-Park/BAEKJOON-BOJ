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

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	vector<int> loc(n + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		loc[x] = i;
	}


	vector<int> part;

	int sz = 0;
	int maxloc = 0;
	for (int i = 0; i < n; i++)
	{
		int x = v[i];
		maxloc = max(maxloc, loc[x]);
		sz++;
		if (maxloc == i)
		{
			part.push_back(sz);
			sz = 0;
		}
	}

	int ans = 0;
	int cur = 0;
	for (int i = 0; i < part.size(); i++)
	{
		cur += part[i];
		if (cur >= k)
		{
			ans++;
			cur = 0;
		}
	}
	cout << ans;

	return 0;
}