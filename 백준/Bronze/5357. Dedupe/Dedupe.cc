#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		string s;
		cin >> s;
		string res = "";
		char prev = '\0';
		for (auto c : s)
		{
			if (prev != c)
			{
				res += c;
				prev = c;
			}
		}
		cout << res << '\n';
	}

	return 0;
}
