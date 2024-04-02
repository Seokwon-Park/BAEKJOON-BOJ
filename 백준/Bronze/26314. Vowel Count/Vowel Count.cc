#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
		int vow = 0;
		int con = 0;
		for (char c : s)
		{
			bool isVow = false;
			for (char vow : "aeiou")
			{
				if (c == vow)
				{
					isVow = true;
					break;
				}
			}
			if (!isVow)
				con++;
			else
				vow++;
		}
		cout << s << '\n' << (vow>con? 1 :0) << '\n';
	}

	return 0;
}