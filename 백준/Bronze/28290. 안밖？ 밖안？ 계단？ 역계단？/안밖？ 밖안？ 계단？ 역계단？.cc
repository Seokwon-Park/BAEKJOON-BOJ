#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	map<string, string> m;
	m["fdsajkl;"] = "in-out";
	m["jkl;fdsa"] = "in-out";
	m["asdf;lkj"] = "out-in";
	m[";lkjasdf"] = "out-in";
	m["asdfjkl;"] = "stairs";
	m[";lkjfdsa"] = "reverse";

	string s;
	cin >> s;
	cout << (m.find(s) == m.end()?"molu":m[s]);

	return 0;
}
