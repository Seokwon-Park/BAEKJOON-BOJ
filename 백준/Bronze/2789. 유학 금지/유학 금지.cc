#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool banned[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for (auto c : "CAMBRIDGE")
	{
		banned[c - 'A'] = true;
	}
	string s, ans = "";
	cin >> s;
	for (auto c : s)
	{
		if (!banned[c - 'A'])
			ans += c;
	}
	cout << ans;
	

	return 0;
}