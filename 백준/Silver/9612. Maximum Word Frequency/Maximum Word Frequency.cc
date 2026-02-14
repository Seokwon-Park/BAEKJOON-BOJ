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
	Hash<string, int> cnt;
	int mx = 0;
	while (n--)
	{
		string s;
		cin >> s;
		cnt[s]++;
		mx = max(mx,cnt[s]);
	}

	vector<string> res;
	for (auto [s, x] : cnt)
	{
		if (x == mx)
		{
			res.push_back(s);
		}
	}

	sort(res.begin(), res.end());
	cout << res.back() << ' ' << mx;

	return 0;
}