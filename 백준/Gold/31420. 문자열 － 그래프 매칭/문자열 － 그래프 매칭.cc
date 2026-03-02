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

bool isValid[26 * 26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string str;
	vector<int> s;
	s.reserve(str.size());
	cin >> n >> str;
	for (auto c : str)
	{
		s.push_back(c - 'a');
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		char u, v;
		cin >> u >> v;
		u -= 'a';
		v -= 'a';
		isValid[u * 26 + v] = 1;
	}

	int l = 0;
	int r = 0;
	int rr = 0;
	int edgesize = 0;
	vector<int> cnts(26 * 26);
	ll ans = 0;
	while (l + 1 < n)
	{
		if (edgesize == t) // 필요한 그래프 엣지수를 갖추면
		{
			if (rr < r)rr = r;

			while (rr + 1 < n)
			{
				int checkid = s[rr] * 26 + s[rr + 1];
				if (!isValid[checkid])//유효하지 않은 엣지를 찾으면
				{
					break;
				}
				rr++;
			}
			ans += rr - r + 1;
			int removeid = s[l] * 26 + s[l + 1];
			cnts[removeid]--;
			if (cnts[removeid] == 0)
			{
				edgesize--;
			}
			l++;
			continue;
		}

		if (r + 1 >= n) break;

		if (l > r) r = l;
		int edgeid = s[r] * 26 + s[r + 1];
		if (!isValid[edgeid]) // 엣지가 유효하지 않으면
		{
			cnts.assign(26 * 26, 0);
			edgesize = 0;

			r = r + 1;
			l = r;
			continue;
		}

		if (cnts[edgeid] == 0) // 엣지가 포함되어 있지 않으면
		{
			edgesize++;
		}
		cnts[edgeid]++;
		r++;
	}
	cout << ans;

	return 0;
}