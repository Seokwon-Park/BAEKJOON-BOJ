#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		string s;
		cin >> s;

		int ix = 0;
		bool isValid = true;
		while (ix < s.size())
		{
			if (ix + 2 < s.size() && s[ix] == '1' && s[ix + 1] == '0' && s[ix + 2] == '0')
			{
				ix += 3;
				if (ix >= s.size())
				{
					isValid = false;
					break;
				}
				bool brflag = false;
				while (s[ix] == '0')
				{
					ix++;
					if (ix >= s.size())
					{
						isValid = false;
						brflag = true;
						break;
					}
				}
				if (brflag) break;
				int onecnt = 0;
				while (s[ix] == '1')
				{
					ix++;
					onecnt++;
				}
				if (ix + 1 < s.size() && s[ix] == '0' && s[ix + 1] == '0')
				{
					if (onecnt > 1)
					{
						ix--;
						continue;
					}
					else
					{
						isValid = false;
						break;
					}
				}
			}
			else if (ix + 1 < s.size() && s[ix] == '0' && s[ix + 1] == '1')
			{
				ix += 2;
			}
			else
			{
				isValid = false;
				break;
			}
		}
		if (isValid)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	


	return 0;
}