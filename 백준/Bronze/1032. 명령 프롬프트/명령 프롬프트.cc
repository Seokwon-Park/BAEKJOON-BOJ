#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string cmp = "";
	string pattern = "";
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		if (cmp.length() == 0)
		{
			cmp = str;
		}
		else
		{
			for (int i = 0; i < str.length(); i++)
			{
				if (cmp[i] != str[i])
					pattern += '?';
				else
					pattern += cmp[i];
			}
			cmp = pattern;
			pattern = "";
		}
	}

	cout << cmp;

	return 0;
}