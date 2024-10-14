#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

bool isV(char c)
{
	if (c == 'a' ||
		c == 'e' ||
		c == 'i' ||
		c == 'o' ||
		c == 'u')
		return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	while (cin >> s, s != "#")
	{
		int ix = 0;
		while (ix <s.size() && !isV(s[ix]))	ix++;
			
		string ans = s.substr(ix) + s.substr(0, ix) + "ay";
		cout << ans << '\n';
	}

	return 0;
}