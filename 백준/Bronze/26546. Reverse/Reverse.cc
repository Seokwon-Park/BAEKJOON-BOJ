#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		string str;
		int s, e;
		cin >> str >> s >> e;
		string ans;
		for (int i = 0; i < str.size(); i++)
		{
			if (i < s || i >= e)
				ans += str[i];
		}
		cout << ans << '\n';
	}

	return 0;
}