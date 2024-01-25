#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	getline(cin, str);
	string res = "";

	for (auto c : str)
	{
		if (isalpha(c))
		{
			if (c >= 'a' && c <= 'z')
			{
				c = ((c + 13) - 'a') % 26 + 'a';
			}
			if (c >= 'A' && c <= 'Z')
			{
				c = ((c + 13) - 'A') % 26 + 'A';
			}
			res += c;
		}
		else
			res += c;
	}

	cout << res;

	return 0;
}