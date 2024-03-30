#include <bits/stdc++.h>

using namespace std;

using ll = long long;

string crypt[8];


string findCh(const string& s, int st)
{
	for (int i = 0; i < 8; i++)
	{
		int diff = 0;
		bool isAlpha = true;
		for (int j = 0; j < 6; j++)
		{
			if (crypt[i][j] != s[st + j])
				diff++;
			if (diff > 1)
			{
				isAlpha = false;
				break;
			}
		}
		if (isAlpha)
			return string(1, 'A' + i);
	}
	return "-1";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	crypt[0] = "000000";
	crypt[1] = "001111";
	crypt[2] = "010011";
	crypt[3] = "011100";
	crypt[4] = "100110";
	crypt[5] = "101001";
	crypt[6] = "110101";
	crypt[7] = "111010";

	int n;
	cin >> n;
	string s;
	cin >> s;
	string res;
	for (int i = 0; i < s.size(); i += 6)
	{
		string tmp = findCh(s, i);
		if (tmp != "-1")
			res += tmp;
		else
		{
			cout << i / 6 + 1;
			return 0;
		}
	}

	cout << res;

	return 0;
}