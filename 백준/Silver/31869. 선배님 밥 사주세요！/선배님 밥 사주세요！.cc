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

bool bob[75];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	Hash<string, tiii> h;
	for (int i = 0; i < n; i++)
	{
		string s;
		int w, d, p;
		cin >> s >> w >> d >> p;
		h[s] = tie(w,d,p);
	}

	for (int i = 0; i < n; i++)
	{
		string s;
		int m;
		cin >> s >> m;
		auto [w, d, p] = h[s];
		if (p <= m)
		{
			bob[(w - 1) * 7 + d] = true;
		}
	}

	int ans = 0;
	int cur = 0;
	for (int i = 0; i < 70; i++)
	{
		if (bob[i])
		{
			cur++;
		}
		else
		{
			ans = max(ans, cur);
			cur= 0;
		}
	}
	ans = max(ans, cur);
	cout << ans;

	return 0;
}