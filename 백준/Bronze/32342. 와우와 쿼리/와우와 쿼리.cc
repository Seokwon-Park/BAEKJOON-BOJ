#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;
template <typename key, typename value>
using hashm = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		
		int ans = 0;
		if (s.size() >= 3)
		{
			for (int j = 0; j <= s.size() - 3; j++)
			{
				if (s[j] == 'W' && s[j + 1] == 'O' && s[j + 2] == 'W')
				{
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}