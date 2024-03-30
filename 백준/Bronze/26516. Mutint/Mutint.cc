#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		string s;
		cin >> s;
		if (s == "0")break;
		int ix = max_element(s.begin(), s.end()) - s.begin();
		int d = s[ix] - '0';
		if (d % 2)
		{
			s[ix] = '0';
		}
		else
		{
			d += 4;
			if (d > 9)
				d = d % 10;
			s[ix] = d + '0';
		}

		int loc = 0;
		while (s[loc] == '0')
		{
			loc++;
		}
		if (loc == s.size())
			s = "0";
		else
			s = s.substr(loc);

		cout << s << '\n';
	}

	return 0;
}