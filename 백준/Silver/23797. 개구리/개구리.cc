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

	string s;
	cin >> s;
	int ans = 0;
	int k = 0;
	int p = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'K')
		{
			k++;
			if (p <= 0)
				ans++;
			else
				p--;
		}
		else
		{
			p++;
			if (k <= 0)
				ans++;
			else
				k--;
		}
	}
	cout << ans;

	return 0;
}