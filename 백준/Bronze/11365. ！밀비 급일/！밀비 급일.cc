#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	while (true)
	{
		string s;
		getline(cin, s);
		if (s == "END") break;
		for (int i = 0; i < s.size() / 2; i++)
		{
			swap(s[i], s[s.size() - 1 - i]);
		}
		cout << s << '\n';
	}

	return 0;
}