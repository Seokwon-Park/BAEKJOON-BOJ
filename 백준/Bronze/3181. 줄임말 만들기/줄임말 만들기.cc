#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	getline(cin, s);
	istringstream iss(s);
	string tmp;
	string ans = "";
	map<string, bool> isIgnore;
	isIgnore["i"] = true;
	isIgnore["pa"] = true;
	isIgnore["te"] = true;
	isIgnore["ni"] = true;
	isIgnore["niti"] = true;
	isIgnore["a"] = true;
	isIgnore["ali"] = true;
	isIgnore["nego"] = true;
	isIgnore["no"] = true;
	isIgnore["ili"] = true;

	while (getline(iss, tmp, ' '))
	{
		if (!ans.empty() && isIgnore[tmp]) continue;
		ans += toupper(tmp[0]);
	}
	cout << ans;

	return 0;
}
