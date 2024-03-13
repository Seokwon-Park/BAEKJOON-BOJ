#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s[26];
	s['N'-'A'] = "North London Collegiate School";
	s['B'-'A'] = "Branksome Hall Asia";
	s['K'-'A'] = "Korea International School";
	s['S'-'A'] = "St. Johnsbury Academy";

	string c;
	cin >> c;
	cout << s[c[0] - 'A'];

	return 0;
}