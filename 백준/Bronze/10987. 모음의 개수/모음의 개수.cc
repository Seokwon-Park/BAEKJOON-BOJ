#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string str;
	cin >> str;
	cout << count_if(str.begin(), str.end(), [](const auto& c)
		{
			if (
				c == 'a' ||
				c == 'e' ||
				c == 'i' ||
				c == 'o' ||
				c == 'u'
				)
				return true;
			return false;
		});

	return 0;
}
