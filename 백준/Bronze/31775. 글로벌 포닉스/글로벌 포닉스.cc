#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	string s = "";
	s += s1[0];
	s += s2[0];
	s += s3[0];
	sort(s.begin(), s.end());

	if (s == "klp")
		cout << "GLOBAL";
	else
		cout << "PONIX";

	return 0;
}
