#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	vector<int> pos(26, -1);
	int ans = 0;
	for (int i = 0; i< 52; i++)
	{
		if (pos[s[i] - 'A'] != -1)
		{
			vector<int> v(26, 0);
			for (int j = pos[s[i] - 'A']+1; j < i; j++)
			{
				v[s[j] - 'A']++;
			}
			ans += count(v.begin(), v.end(), 1);
		}
		else
			pos[s[i] - 'A'] = i;
	}
	cout << ans/2;

	return 0;
}