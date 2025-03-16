#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string big = "12010000000000111100000000";
	string small = "11011010000000111000000000";

	string s;
	getline(cin, s);
	int ans = 0;
	for (auto c : s)
	{
		if (c == ' ') continue;
		else if (c >= 'a' && c <= 'z')
		{
			ans += small[c - 'a'] - '0';
		}
		else if (c >= 'A' && c <= 'Z')
		{
			ans += big[c - 'A'] - '0';
		}
		else if (c == '@')
		{
			ans++;
		}
	}
	cout << ans;

	return 0;
}