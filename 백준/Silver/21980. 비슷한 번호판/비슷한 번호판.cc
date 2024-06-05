#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, k;
		cin >> n >> k;
		map<string, map<int, int>> mm;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			int upcase = 0;
			for (auto& c:s)
			{
				if (c >= 'A' && c <= 'Z')
				{
					upcase++;
					c = tolower(c);
				}
			}
			sort(s.begin(), s.end());
			mm[s][upcase]++;
		}
		int ans = 0;
		for (auto [s, mp]:mm)
		{
			for (auto [up, m] : mp)
			{
				ans += m * (m - 1) / 2;
			}
		}
		cout << ans << '\n';
	}


	return 0;
}