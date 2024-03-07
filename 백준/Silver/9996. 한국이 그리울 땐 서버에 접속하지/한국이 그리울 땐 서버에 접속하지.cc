#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string str;
	cin >> str;

	istringstream iss(str);
	vector<string> p;
	string tmp;
	while (getline(iss, tmp, '*'))
	{
		p.push_back(tmp);
	}
	
	while (n--)
	{
		string s;
		cin >> s;
		string st, ed;
		if (str.length() - 1 > s.length())
		{
			cout << "NE\n";
			continue;
		}

		if (p[0].length() <= s.length())
			 st = s.substr(0, p[0].length());
		if (p[1].length() <= s.length())
			 ed = s.substr(s.length()-p[1].length());

		if (st == p[0] && ed == p[1])
			cout << "DA\n";
		else
			cout << "NE\n";
		
	}

	return 0;
}
