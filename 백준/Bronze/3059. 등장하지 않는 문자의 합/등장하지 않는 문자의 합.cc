#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		string s;
		cin >> s;
		vector<bool> isused(26, false);
		for (auto c : s)
		{
			isused[c - 'A'] = true;
		}
		int ans = 0;
		for (int i = 0; i < 26; i++)
		{
			if (!isused[i])
				ans += i + 'A';
		}
		cout << ans << '\n';
	}

	return 0;
}