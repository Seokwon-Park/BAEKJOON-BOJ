#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true)
	{
		char ch;
		cin >> ch;
		if (ch == '#')break;
		string s;
		cin.ignore();
		getline(cin, s);
		int ans = 0;
		for (auto c : s)
		{
			c = tolower(c);
			if (c - 'a' == ch - 'a')
				ans++;
		}
		cout << ch << ' ' << ans << '\n';
	}
	return 0;
}