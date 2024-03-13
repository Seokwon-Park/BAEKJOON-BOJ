#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		string s;
		cin >> s;
		if (s.size() < 6 || s.size() > 9)
			cout << "no";
		else
			cout << "yes";
		cout << '\n';
	}
	
	return 0;
}