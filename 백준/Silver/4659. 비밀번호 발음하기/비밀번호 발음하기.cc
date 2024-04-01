#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	while (1)
	{
		cin >> s;
		if (s == "end") break;
		bool chk1 = false;
		bool chk2 = true;
		bool chk3 = true;
		int j = 0, m = 0;
		char prev = '\0';
		for (auto c : s)
		{
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			{
				chk1 = true; // 모음하나 반드시 포함.
				m++;
				j = 0;
			}
			else
			{
				j++;
				m = 0;
			}
			if (m >= 3 || j >= 3)
				chk2 = false;
			if (prev == c)
			{
				if (c != 'e' && c != 'o')
				{
					chk3 = false;
				}
			}
			prev = c;
		}
		if (chk1 && chk2 && chk3)
			cout << '<' << s << "> is acceptable.";
		else
			cout << '<' << s << "> is not acceptable.";
		cout << '\n';
	}


	return 0;
}