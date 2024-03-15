#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != t[i])
			ans++;
	}
	cout << ans;

	return 0;
}