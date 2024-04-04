#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	int n = s.size();
	int res = 0;
	if (s[0] == '0')
	{
		if (s[1] == 'x') // hex
		{
			int hex = 1;
			for (int i = n - 1; i >= 2; i--)
			{
				int val;
				if (s[i] <= '9' && s[i] >= '0')
				{
					val = s[i] - '0';
				}
				else
				{
					val = s[i] - 'a' + 10;
				}
				res += val * hex;
				hex *= 16;
			}
		}
		else
		{
			int oct = 1;
			for (int i = n - 1; i >= 1; i--)
			{
				int val = s[i] - '0';
				res += val * oct;
				oct *= 8;
			}
		}
	}
	else
	{
		res = stoi(s);
	}
	cout << res;


	return 0;
}