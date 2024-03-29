#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	int cnt = 0;
	while (tc--)
	{
		string s;
		cin >> s;
		for (int i = 0; i < s.size()-1; i++)
		{
			if (s[i] == 'O' && s[i + 1] == 'I')
			{
				cnt++;
				break;
			}
			else if (s[i] == '0' && s[i + 1] == '1')
			{
				cnt++;
				break;
			}
		}
	}
	cout << cnt;

	return 0;
}