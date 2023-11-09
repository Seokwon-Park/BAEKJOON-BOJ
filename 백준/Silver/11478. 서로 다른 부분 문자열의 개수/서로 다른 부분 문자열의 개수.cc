#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	set<string> s;

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < str.length()-i; j++)
		{
			string c = str.substr(j, i+1);
			s.insert(c);
		}
	}

	cout << s.size();


	return 0;
}