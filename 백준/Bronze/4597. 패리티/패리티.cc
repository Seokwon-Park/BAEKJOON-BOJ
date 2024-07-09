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
	while (1)
	{
		cin >> s;
		if (s == "#")break;
		int bit = 0;
		string ans = "";
		for (int i = 0; i < s.size() - 1; i++)
		{
			ans += s[i];
			bit += (s[i] == '1');
		}
		if (s[s.size() - 1] == 'e')
		{
			if (bit % 2 == 0)
				ans += '0';
			else
				ans += '1';
		}
		else
		{
			if (bit % 2 == 0)
				ans += '1';
			else
				ans += '0';
		}
		cout << ans << '\n';
	}


	return 0;
}