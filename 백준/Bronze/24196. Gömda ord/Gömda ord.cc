#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	string ans;
	int ix = 0;
	while (ix < s.size())
	{
		ans += s[ix];
		int nxt = s[ix] - 'A' + 1;
		ix += nxt;
	}
	cout << ans;
	

	return 0;
}