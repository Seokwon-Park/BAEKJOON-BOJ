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

	int n, m;
	cin >> n >> m;
	vector<int> v(n);

	int limit = 9 * m / 10 + (9 * m % 10 > 0);
	bool possible = false;
	map<int, int> cnt;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		if (i < m)
		{
			cnt[v[i]]++;
			if (cnt[v[i]] >= limit)
			{
				possible = true;
			}
		}
	}

	if (possible)
	{
		cout << "YES";
		return 0;
	}

	int st = 0;
	for (int en = m; en < n; en++)
	{
		cnt[v[st]]--;
		cnt[v[en]]++;
		if (cnt[v[en]] >= limit)
		{
			cout << "YES";
			return 0;
		}
		st++;
	}

	cout << "NO";

	return 0;
}