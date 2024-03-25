#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	map<string, char> m;
	m["AA"] = 'A';
	m["AG"] = 'C';
	m["AC"] = 'A';
	m["AT"] = 'G';

	m["GA"] = 'C';
	m["GG"] = 'G';
	m["GC"] = 'T';
	m["GT"] = 'A';

	m["CA"] = 'A';
	m["CG"] = 'T';
	m["CC"] = 'C';
	m["CT"] = 'G';

	m["TA"] = 'G';
	m["TG"] = 'A';
	m["TC"] = 'G';
	m["TT"] = 'T';

	int n;
	cin >> n;
	string s;
	cin >> s;

	while (s.size() >= 2)
	{
		string tmp(s.end() - 2, s.end());
		s.pop_back();
		s.pop_back();
		s += m[tmp];
	}
	cout << s;
	
	return 0;
}