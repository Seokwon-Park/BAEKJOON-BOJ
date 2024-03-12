#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s[256];
	s['S'] = "HIGHSCHOOL";
	s['C'] = "MASTER";
	s['2'] = "0611";
	s['A'] = "CONTEST";

	string in;
	cin >> in;
	cout << s[*in.begin()];

	return 0;
}