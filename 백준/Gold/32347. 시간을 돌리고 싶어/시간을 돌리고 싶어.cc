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

int n, k;
vector<int> on;


bool solve(int mid)
{
	int cur = n - 1;
	int tm = 0;
	while (cur)
	{
		int nxt = max(cur - mid, 0);
		tm++;
		if (nxt == 0) return tm <= k;
		auto itr = *lower_bound(on.begin(), on.end(), nxt);
		if (itr >= cur) return false;
		cur = itr;
	}
	return tm <= k;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		if(v[i]) on.push_back(i);
	}

	int st = 0;
	int en = n;
	while (st + 1 < en)
	{
		int mid = (st + en) / 2; // T
		if (solve(mid))
		{
			en = mid;
		}
		else
		{
			st = mid;
		}
	}
	cout << en;

	return 0;
}