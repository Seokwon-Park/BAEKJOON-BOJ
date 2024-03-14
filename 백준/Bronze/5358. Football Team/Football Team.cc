#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	while (getline(cin,s))
	{
		for (auto& c : s)
		{
			if (c == 'i')
				c = 'e';
			else if (c == 'e')
				c = 'i';
			else if (c == 'I')
				c = 'E';
			else if ( c== 'E' )
				c = 'I';
		}
		cout << s << '\n';

	}

	return 0;
}