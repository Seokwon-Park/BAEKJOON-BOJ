#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int ix = 0;
	while (ix < s.size())
	{
		if (s[ix] == 'p')
		{
			if (ix + 1 < s.size())
			{
				if (s[ix + 1] != 'i')
				{
					cout << "NO";
					return 0;
				}
				else
				{
					ix += 2;
				}
			}
			else
			{
				cout << "NO";
				return 0;
			}
		}
		else if (s[ix] == 'k')
		{
			if (ix + 1 < s.size())
			{
				if (s[ix + 1] != 'a')
				{
					cout << "NO";
					return 0;
				}
				else
				{
					ix += 2;
				}
			}
			else
			{
				cout << "NO";
				return 0;
			}
		}
		else if (s[ix] == 'c')
		{
			if (ix + 2 < s.size())
			{
				if (s[ix + 1] == 'h' && s[ix+2] == 'u')
				{
					ix += 3;
				}
				else
				{
					cout << "NO";
					return 0;
				}
			}
			else
			{
				cout << "NO";
				return 0;
			}
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";


	return 0;
}