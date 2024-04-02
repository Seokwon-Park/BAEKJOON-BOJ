#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int b[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s, t;
	while (cin >> s >> t)
	{
		int ix = 0;
		bool isSub = false;
		for (char c : t)
		{
			if (c == s[ix])
			{
				ix++;
			}
			if (ix == s.size())
			{
				isSub = true;
				break;
			}
		}
		if (isSub)
			cout << "Yes";
		else
			cout << "No";
		cout << '\n';
	}


	return 0;
}