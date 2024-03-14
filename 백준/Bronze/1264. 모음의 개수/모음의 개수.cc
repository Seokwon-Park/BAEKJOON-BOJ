#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	while (getline(cin, s))
	{
		if (s == "#") break;
		cout << count_if(s.begin(), s.end(), [](const char& ch) {
			char c = tolower(ch);
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				return true;
			return false;
			}) << '\n';
	}



	return 0;
}