#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

string s, t;
string srev;

bool findAns = false;

void func(string& a, bool isRev)
{
	if (findAns) return;
	if (a.length() == s.length())
	{
		if (isRev)
			findAns = (a == srev);
		else
			findAns = (a == s);
		return;
	}
	if (!isRev)
	{ 
		if (*a.rbegin() == 'A')
		{
			a.pop_back();
			func(a, isRev);
			a.push_back('A');
		}
	}
	else
	{
		if (*a.begin() == 'A')
		{
			string tmp = a;
			a = a.substr(1);
			func(a, isRev);
			a = tmp;
		}
	}
	if (findAns) return;
	if (isRev)
	{
		if (*a.rbegin() == 'B')
		{
			a.pop_back();
			func(a, !isRev);
			a.push_back('B');
		}
	}
	else
	{
		if (*a.begin() == 'B')
		{
			string tmp = a;
			a = a.substr(1);
			func(a, !isRev);
			a = tmp;
		}
	}   
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> s >> t;

	srev = string(s.rbegin(), s.rend());
	func(t, false);
	cout << findAns;

	return 0;
}